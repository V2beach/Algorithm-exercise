#pragma warning(disable: 4996)
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

long long binarySearch(long long* array, vector<long long*> &answer, long long left, long long right, long long value) {
	long long mid, *diamonds = new long long[2];
	diamonds[0] = left;
	while (left < right) {
		mid = (left + right) / 2;
		if (diamonds[0] == 0 && array[mid] >= value) right = mid;//防止越界
		else if (array[mid] - array[diamonds[0] - 1] >= value) right = mid;
		else left = mid + 1;
	}
	long long diff = diamonds[0] == 0 ? array[left] - value : array[left] - array[diamonds[0] - 1] - value;
	diamonds[0]++;
	diamonds[1] = left + 1;
	answer.push_back(diamonds);
	return diff;
}

int main(int argc, char *argv[]) {
	long long N, M;
	scanf("%lld %lld", &N, &M);
	long long *diamonds = new long long[N];
	long long sum = 0;
	for (long long i = 0; i < N; i++) {
		scanf("%lld", &diamonds[i]);
		sum += diamonds[i];
		diamonds[i] = sum;
	}
	vector<long long*> answer;
	long long *diff = new long long[N];
	long long minDiff = M;//最小的差值不会大过所需金额
	for (long long i = 0; i < N; i++) {
		diff[i] = binarySearch(diamonds, answer, i, N - 1, M);//如果没有刚好相等的就存到第一个大于所需金额的位置，记录每个序列和金额的差值，都没有则空
		if (diff[i] >= 0 && minDiff > diff[i]) minDiff = diff[i];
	}
	for (long long i = 0; i < N; i++)
		if (minDiff == diff[i])
			printf("%lld-%lld\n", answer[i][0], answer[i][1]);
	system("pause");
	return 0;
}
//这篇代码要重新读，还没有看书上的题解。
//算法笔记上面的思路非常简单但是非常漂亮，应该学习这种思路，很棒
//即，从5到7的和其实就是sum[7] - sum[4]，所以只需要求一个累加数组