#pragma warning(disable: 4996)
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct PAT {
	long userid;
	int finish;
	int total;
	int rank;
	PAT(long userid, int finish, int total) {
		this->userid = userid;
		this->finish = finish;
		this->total = total;
	}
};

bool cmp(PAT testeeA, PAT testeeB) {
	if (testeeA.total != testeeB.total) return testeeA.total > testeeB.total;
	else if (testeeA.finish != testeeB.finish) return testeeA.finish > testeeB.finish;
	else return testeeA.userid < testeeB.userid;
}

int main(int argc, char *argv[]) {
	int N, K;
	long M;//submissions
	scanf("%d %d %ld", &N, &K, &M);
	int *fullmark = new int[K];
	for (int i = 0; i < K; i++)
		scanf("%d", &fullmark[i]);

	long **records = new long*[100000];
	for (int i = 0; i < 100000; i++) {
		records[i] = new long[K];//咋初始化啊...
		memset(records[i], -2, K * sizeof(records[i]));
	}

	long userid;
	int problemid, partialscore, cur = 0;
	map<long, vector<bool>> flag;//记录有哪些学生参加考试了，这里主要是这个作用，其次是记录全对的题目数
	map<long, vector<bool>>::iterator itemp;
	for (int i = 0; i < M; i++) {
		scanf("%ld %d %d", &userid, &problemid, &partialscore);
		if (partialscore >= 0) {
			itemp = flag.find(userid);
			if (partialscore == fullmark[problemid - 1])//所有测试点通过
				if (itemp == flag.end()) {//map找不到key会返回指到end的迭代器
					vector<bool> vtemp(K, false);
					vtemp[problemid - 1] = true;
					flag.insert(map<long, vector<bool>>::value_type(userid, vtemp));
				}
				else itemp->second[problemid - 1] = true;//而不是单纯itemp->second++;
			else //有测试点没过
				if (itemp == flag.end()) {
					vector<bool> vtemp(K, false);
					flag.insert(map<long, vector<bool>>::value_type(userid, vtemp));
				}
		}
		else;

		if (records[userid][problemid - 1] < partialscore)
			records[userid][problemid - 1] = partialscore;
	}

	//printf("%d", flag.size());
	vector<PAT> testees;
	for (map<long, vector<bool>>::iterator it = flag.begin(); it != flag.end(); it++) {
		int total = 0, finish = 0;
		vector<bool> vtemp = it->second;
		for (int i = 0; i < vtemp.size(); i++)
			if (vtemp[i])
				finish++;
		for (int i = 0; i < K; i++)
			if (records[it->first][i] > 0)
				total += records[it->first][i];
		PAT testee(it->first, finish, total);
		testees.push_back(testee);
	}

	sort(testees.begin(), testees.end(), cmp);
	testees[0].rank = 1;
	for (int i = 0; i < testees.size(); i++) {
		if (i > 0)
			if (testees[i].total == testees[i - 1].total)
				testees[i].rank = testees[i - 1].rank;
			else
				testees[i].rank = i + 1;
		else;
		printf("%d %05ld %d", testees[i].rank, testees[i].userid, testees[i].total);
		for (int j = 0; j < K; j++) {
			if (records[testees[i].userid][j] < -1) printf(" -");//没提交过
			else if (records[testees[i].userid][j] == -1) printf(" 0");//编译没通过
			else printf(" %d", records[testees[i].userid][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
/*
多输出了一个0，半天没有看见，吐血...
关于测试点4，你提交了一次满分答案，还可以再提交一次满分答案，答对题次数是不变的！
为自己的失误，在镜子前给自己重重磕三个响头。
4 3 8
20 30 40
00001 1 15
00001 3 20
00002 2 0
00002 3 0
00003 1 20
00003 2 15
00004 1 -1
00004 3 -1
*/