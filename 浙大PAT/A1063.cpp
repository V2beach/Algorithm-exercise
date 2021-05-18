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
		set1--; set2--;//从0计数和从1计数的区别
		rate = computeSets(sets[set1], sets[set2]);
		printf("%.1lf%%\n", rate);
	}
	system("pause");
	return 0;
}
//备注，打印百分号%%，还有下面的这一条。
//set和unordered_set，map和unordered_map，学习一下实现原理和优缺点！
//下面是原先的写法，巨简单，但是因为合并set时间复杂度有点高导致最后一组测试数据超时。
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
//		set1--; set2--;//从0计数和从1计数的区别
//		temp.insert(sets[set1].begin(), sets[set1].end());
//		temp.insert(sets[set2].begin(), sets[set2].end());
//		rate = double(sets[set1].size() + sets[set2].size() - temp.size()) / double(temp.size()) * 100.0;
//		printf("%.1lf%%\n", rate);
//	}
//	system("pause");
//	return 0;
//}