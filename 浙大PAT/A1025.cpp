#pragma warning(disable: 4996)
#include <cstdio>
#include <algorithm>
#include <vector>

//#define getArrayLength(array, len) {len = sizeof(array) / sizeof(array[0]);}
//template <class T>
//int getArrayLength(T &array) {
//	return sizeof(array) / sizeof(array[0]);
//}

using namespace std;

struct Testee {
	//string id;
	long long id;
	int score;
	int location;
	int finalRank;
	int localRank;
};

bool cmp(Testee a, Testee b) {//������ȫ��Ԫ�ز����ö�ά����
	if (a.score != b.score) return a.score > b.score;
	else return b.id > a.id;
}

int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);
	vector<Testee> testees;
	//ios::sync_with_stdio(false);
	for (int i = 0; i < N; i++) {
		int K;
		scanf("%d", &K);
		vector<Testee> localTestees(K);
		for (int j = 0; j < K; j++) {
			scanf("%lld %d", &localTestees[j].id, &localTestees[j].score);
			localTestees[j].location = i + 1;
		}
		sort(localTestees.begin(), localTestees.end(), cmp);
		localTestees[0].localRank = 1;
		testees.push_back(localTestees[0]);
		for (int j = 1; j < K; j++) {
			localTestees[j].localRank = localTestees[j].score < localTestees[j - 1].score ? j + 1 : localTestees[j - 1].localRank;
			testees.push_back(localTestees[j]);
		}
	}

	sort(testees.begin(), testees.end(), cmp);
	testees[0].finalRank = 1;
	for (int i = 1; i < testees.size(); i++)
		testees[i].finalRank = testees[i].score < testees[i - 1].score ? i + 1 : testees[i - 1].finalRank;

	printf("%d", testees.size());
	for (int i = 0; i < testees.size(); i++)
		printf("\n%013lld %d %d %d", testees[i].id, testees[i].finalRank, testees[i].location, testees[i].localRank);//������Ҫ013����Ϊ�����0��ͷ�Ļ������ͻὫ0ʡ������string�ֻᳬ�ڴ�

	system("pause");
	return 0;
}
//�ڴ泬�ޣ��������ʺţ�����������string�����⣬û�뵽
//����ʵҲû��Ҫ��cin/cout�ˣ���������Ϊ��string���õ�