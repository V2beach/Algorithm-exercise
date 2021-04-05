#pragma warning(disable: 4996)
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Applicant {
	int id, ge, gi, g, rank, *choices, school;
};

bool cmp1(Applicant a, Applicant b) {
	if (a.g != b.g)return a.g > b.g;
	else if (a.ge != b.ge) return a.ge > b.ge;
	return a.id < b.id;
}

bool cmp2(Applicant a, Applicant b) {
	return a.id < b.id;
}

int main(int argc, char *argv[]) {//读研的申请
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int *quota = new int[M];//限额
	for (int i = 0; i < M; i++)
		scanf("%d", &quota[i]);
	vector<Applicant> applicants(N);
	vector<vector<Applicant>> schools(M);//可能录不满或者录超，就直接用vector了
	int *rank = new int[M];//学校里录取的最低分学生的rank
	//录入申请者数据
	for (int i = 0; i < N; i++) {
		int *choices = new int[K];
		applicants[i].id = i;
		scanf("%d %d", &applicants[i].ge, &applicants[i].gi);
		applicants[i].g = applicants[i].ge + applicants[i].gi;
		for (int j = 0; j < K; j++)
			scanf("%d", &choices[j]);
		applicants[i].choices = choices;
	}
	//申请者排名
	sort(applicants.begin(), applicants.end(), cmp1);
	applicants[0].rank = 0;
	for (int i = 1; i < N; i++) {
		if (applicants[i].ge == applicants[i - 1].ge && applicants[i].gi == applicants[i - 1].gi)
			applicants[i].rank = applicants[i - 1].rank;
		else applicants[i].rank = i;
	}
	//学校按rank录取申请者
	//这里考虑了两种方法，一种是学校选学生，一种是学生选学校，选了后者
	//K个志愿应该是同等的，题目里没说先录满第一志愿再录第二志愿，如果错了再改
	for (int i = 0; i < N; i++) {//第i个学生
		for (int j = 0; j < K; j++) {//的第j个志愿
			if (quota[applicants[i].choices[j]] > 0) {//applicants[i].choices[j]这个就是学校的序号
				schools[applicants[i].choices[j]].push_back(applicants[i]);
				quota[applicants[i].choices[j]]--;
				rank[applicants[i].choices[j]] = applicants[i].rank;
				break;
			}
			else if (rank[applicants[i].choices[j]] == applicants[i].rank) {
				schools[applicants[i].choices[j]].push_back(applicants[i]);
				break;
			}
			else;
		}
	}
	//根据id排序后输出
	for (int i = 0; i < M; i++) {
		if (!schools[i].empty()) {//vector要用empty而不是size==0来判空！
			sort(schools[i].begin(), schools[i].end(), cmp2);
			printf("%d", schools[i][0].id);
			for (int j = 1; j < schools[i].size(); j++)
				printf(" %d", schools[i][j].id);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
//写题半小时，提交排队半小时，绝了。
//被我发现了！牛客OJ也有这些题。
//到底为什么所有的用例在我这个MVS上都能跑通，到了OJ就全都不通？
//我真的是被气到吐血了，又是浪费了整整三个小时！
//踏马我打印的是Applicant schools[i][j]，mvs会自动输出第一个值int id，所以我没有发现！
//第一！要看warning！！！要看warning！！！要看warning！！！
//第二！牛客OJ打印出来地址，第一反应可能是没初始化，或者就直接输出了地址，第二反应要想一下自己是不是把结构体或者说对象给直接输出了！
//写到题解备注里。
/*
5 5 3
0 0 0 5 5
100 100 0 1 2
100 99 1 2 0
99 100 2 1 0
99 99 1 0 2
98 98 2 0 1

20 3 3
4 7 8
5 3 1 1 0
9 1 2 1 2
9 3 1 0 0
2 6 2 2 0
9 2 2 2 1
7 5 2 0 0
8 9 0 1 1
1 2 0 0 0
9 4 1 2 2
5 0 2 1 1
0 6 0 2 2
6 1 0 0 2
7 6 2 1 0
3 7 0 0 0
5 4 0 2 2
3 0 1 0 0
8 8 0 0 2
4 9 0 0 2
8 9 1 1 0
4 9 0 1 2

6 16 17 19
0 2 8 9 15 18
1 3 4 5 10 11 12 14
*/