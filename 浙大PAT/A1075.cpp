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
		records[i] = new long[K];//զ��ʼ����...
		memset(records[i], -2, K * sizeof(records[i]));
	}

	long userid;
	int problemid, partialscore, cur = 0;
	map<long, vector<bool>> flag;//��¼����Щѧ���μӿ����ˣ�������Ҫ��������ã�����Ǽ�¼ȫ�Ե���Ŀ��
	map<long, vector<bool>>::iterator itemp;
	for (int i = 0; i < M; i++) {
		scanf("%ld %d %d", &userid, &problemid, &partialscore);
		if (partialscore >= 0) {
			itemp = flag.find(userid);
			if (partialscore == fullmark[problemid - 1])//���в��Ե�ͨ��
				if (itemp == flag.end()) {//map�Ҳ���key�᷵��ָ��end�ĵ�����
					vector<bool> vtemp(K, false);
					vtemp[problemid - 1] = true;
					flag.insert(map<long, vector<bool>>::value_type(userid, vtemp));
				}
				else itemp->second[problemid - 1] = true;//�����ǵ���itemp->second++;
			else //�в��Ե�û��
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
			if (records[testees[i].userid][j] < -1) printf(" -");//û�ύ��
			else if (records[testees[i].userid][j] == -1) printf(" 0");//����ûͨ��
			else printf(" %d", records[testees[i].userid][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
/*
�������һ��0������û�п�������Ѫ...
���ڲ��Ե�4�����ύ��һ�����ִ𰸣����������ύһ�����ִ𰸣����������ǲ���ģ�
Ϊ�Լ���ʧ���ھ���ǰ���Լ����ؿ�������ͷ��
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