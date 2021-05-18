#pragma warning(disable: 4996)
#include <cstdio>
#include <algorithm>

using namespace std;

long long binarySearch(long long array[], long long left, long long right, long long val) {//这个代码查找的是第一个大于val的位置
	long long mid;
	while (left < right) {//left == right时已经找到位置了
		mid = (left + right) / 2;
		if (array[mid] > val)//这里可能就是第一个大于的位置
			right = mid;
		else
			left = mid + 1;
	}
	return left;//跟right一样
}

int main(int argc, char *argv[]) {//自己写一个，然后跟算法笔记上的代码和思路对比一下，取长补短
	long long N, p, length = -1;
	scanf("%lld %lld", &N, &p);
	long long *sequence = new long long[N];
	for (long long i = 0; i < N; i++)
		scanf("%lld", &sequence[i]);
	sort(sequence, sequence + N);
	for (long long i = 0; i < N; i++) {
		long long j = binarySearch(sequence, i, N, p * sequence[i]);
		if (j - i > length)
			length = j - i;
	}
	printf("%lld", length);
	system("pause");
	return 0;
}
//一次AC，果然还是要看书！
//算法笔记写的思路很详细