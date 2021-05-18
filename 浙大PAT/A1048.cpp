#pragma warning(disable: 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int* a, int* b) {
	return a[0] < b[0];
}

int main(int argc, char *argv[]) {
	long N;
	int M;
	scanf("%ld %d", &N, &M);
	int hashTable[10001];//可能是两个一样的？
	memset(hashTable, 0, 10001 * sizeof(int));
	int *coins = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &coins[i]);
		hashTable[coins[i]]++;
	}
	vector<int*> result;//不能直接int[2]？
	for (int i = 0; i < N; i++) {
		if (coins[i] + coins[i] == M)
			if (hashTable[coins[i]] > 1) {
				int *temp = new int[2];
				temp[0] = coins[i];
				temp[1] = coins[i];
				result.push_back(temp);
			}
			else;
		else
			if (hashTable[M - coins[i]] > 0) {
				int *temp = new int[2];
				coins[i] < M - coins[i] ? (temp[0] = coins[i], temp[1] = M - coins[i]) : (temp[1] = coins[i], temp[0] = M - coins[i]);
				result.push_back(temp);
			}
	}
	if (result.empty())
		printf("No Solution");
	else {
		sort(result.begin(), result.end(), cmp);
		printf("%d %d", result[0][0], result[0][1]);
	}
	system("pause");
	return 0;
}
//太怪了，又是这种情况，g++和clang++结果不一样，而且在牛客也跑不通
//这个代码写得太丑了，要改！！！书上的思路不错，从1遍历到M