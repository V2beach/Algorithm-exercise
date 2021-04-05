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

int main(int argc, char *argv[]) {//���е�����
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int *quota = new int[M];//�޶�
	for (int i = 0; i < M; i++)
		scanf("%d", &quota[i]);
	vector<Applicant> applicants(N);
	vector<vector<Applicant>> schools(M);//����¼��������¼������ֱ����vector��
	int *rank = new int[M];//ѧУ��¼ȡ����ͷ�ѧ����rank
	//¼������������
	for (int i = 0; i < N; i++) {
		int *choices = new int[K];
		applicants[i].id = i;
		scanf("%d %d", &applicants[i].ge, &applicants[i].gi);
		applicants[i].g = applicants[i].ge + applicants[i].gi;
		for (int j = 0; j < K; j++)
			scanf("%d", &choices[j]);
		applicants[i].choices = choices;
	}
	//����������
	sort(applicants.begin(), applicants.end(), cmp1);
	applicants[0].rank = 0;
	for (int i = 1; i < N; i++) {
		if (applicants[i].ge == applicants[i - 1].ge && applicants[i].gi == applicants[i - 1].gi)
			applicants[i].rank = applicants[i - 1].rank;
		else applicants[i].rank = i;
	}
	//ѧУ��rank¼ȡ������
	//���￼�������ַ�����һ����ѧУѡѧ����һ����ѧ��ѡѧУ��ѡ�˺���
	//K��־ԸӦ����ͬ�ȵģ���Ŀ��û˵��¼����һ־Ը��¼�ڶ�־Ը����������ٸ�
	for (int i = 0; i < N; i++) {//��i��ѧ��
		for (int j = 0; j < K; j++) {//�ĵ�j��־Ը
			if (quota[applicants[i].choices[j]] > 0) {//applicants[i].choices[j]�������ѧУ�����
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
	//����id��������
	for (int i = 0; i < M; i++) {
		if (!schools[i].empty()) {//vectorҪ��empty������size==0���пգ�
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
//д���Сʱ���ύ�ŶӰ�Сʱ�����ˡ�
//���ҷ����ˣ�ţ��OJҲ����Щ�⡣
//����Ϊʲô���е������������MVS�϶�����ͨ������OJ��ȫ����ͨ��
//������Ǳ�������Ѫ�ˣ������˷�����������Сʱ��
//̤���Ҵ�ӡ����Applicant schools[i][j]��mvs���Զ������һ��ֵint id��������û�з��֣�
//��һ��Ҫ��warning������Ҫ��warning������Ҫ��warning������
//�ڶ���ţ��OJ��ӡ������ַ����һ��Ӧ������û��ʼ�������߾�ֱ������˵�ַ���ڶ���ӦҪ��һ���Լ��ǲ��ǰѽṹ�����˵�����ֱ������ˣ�
//д����ⱸע�
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