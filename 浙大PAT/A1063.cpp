#pragma warning(disable: 4996)
#include <cstdio>
#include <unordered_set>
#include <algorithm>

using namespace std;

double computeSets(unordered_set<long> a, unordered_set<long> b) {
	int fuck = 0;
	unordered_set<long>::iterator it;
	for (it = a.begin(); it != a.end(); it++) {
		if (b.find(*it) != b.end())
			fuck++;
	}
	double rate = double(fuck) / double(a.size() + b.size() - fuck) * 100.0;
	return rate;
}

int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);
	unordered_set<long> *sets = new unordered_set<long>[N];
	for (int i = 0; i < N; i++) {
		int M;
		scanf("%d", &M);
		for (int j = 0; j < M; j++) {
			long num;
			scanf("%ld", &num);
			sets[i].insert(num);
		}
	}
	int K;
	scanf("%d", &K);
	int set1, set2;
	double rate;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &set1, &set2);
		set1--; set2--;//��0�����ʹ�1����������
		rate = computeSets(sets[set1], sets[set2]);
		printf("%.1lf%%\n", rate);
	}
	system("pause");
	return 0;
}
//��ע����ӡ�ٷֺ�%%�������������һ����
//set��unordered_set��map��unordered_map��ѧϰһ��ʵ��ԭ�����ȱ�㣡
//������ԭ�ȵ�д�����޼򵥣�������Ϊ�ϲ�setʱ�临�Ӷ��е�ߵ������һ��������ݳ�ʱ��
//#pragma warning(disable: 4996)
//#include <cstdio>
//#include <set>
//#include <unordered_set>
//#include <algorithm>
//
//using namespace std;
//
//int main(int argc, char *argv[]) {
//	int N;
//	scanf("%d", &N);
//	unordered_set<long> *sets = new unordered_set<long>[N];
//	for (int i = 0; i < N; i++) {
//		int M;
//		scanf("%d", &M);
//		for (int j = 0; j < M; j++) {
//			long num;
//			scanf("%ld", &num);
//			sets[i].insert(num);
//		}
//	}
//	int K;
//	scanf("%d", &K);
//	int set1, set2;
//	double rate;
//	for (int i = 0; i < K; i++) {
//		unordered_set<long> temp;
//		scanf("%d %d", &set1, &set2);
//		set1--; set2--;//��0�����ʹ�1����������
//		temp.insert(sets[set1].begin(), sets[set1].end());
//		temp.insert(sets[set2].begin(), sets[set2].end());
//		rate = double(sets[set1].size() + sets[set2].size() - temp.size()) / double(temp.size()) * 100.0;
//		printf("%.1lf%%\n", rate);
//	}
//	system("pause");
//	return 0;
//}