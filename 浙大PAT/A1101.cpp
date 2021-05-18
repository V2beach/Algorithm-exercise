#pragma warning(disable: 4996)
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	long long N;
	scanf("%lld", &N);
	long long *nums = new long long[N];
	long long nin = 1000000001, nax = -1;
	long long *nins = new long long[N];
	long long *naxs = new long long[N];
	//刚拿到题的思路是记录下每个元素左边的最大值nax和右边的最小值nin，需要遍历两遍。
	for (long long i = 0; i < N; i++) {
		scanf("%lld", &nums[i]);
		naxs[i] = nax;
		if (nax < nums[i])
			nax = nums[i];
	}
	naxs[0] = -1;
	for (long long i = N - 1; i >= 0; i--) {
		nins[i] = nin;
		if (nin > nums[i])
			nin = nums[i];
	}
	nins[N - 1] = 1000000001;
	//看看哪些可以作为pivot
	long long count = 0;
	vector<long long> answer;
	for (long long i = 0; i < N; i++) {
		if (naxs[i] <= nums[i] && nins[i] >= nums[i]) {//千万注意不要把nins和naxs弄反了，最大值是左边的小数，最小值是左边的大数
			answer.push_back(nums[i]);
			count++;
		}
	}
	sort(answer.begin(), answer.end());
	printf("%lld\n", count);
	//for (int i = 0; i < N; i++) {
	//	printf("%lld %lld\n", naxs[i], nins[i]);
	//}
	//system("pause");
	if (answer.empty()) { printf("\n"); return 0; }//一定一定注意这里的格式，格式问题典型！输出0的时候是输出0\n\n，写到备注里。
	printf("%lld", answer[0]);
	for (long long i = 1; i < answer.size(); i++) {
		printf(" %lld", answer[i]);
	}
	system("pause");
	return 0;
}
//一次过，这道题比PATs那道题直观很多，很容易想到。
//一定一定注意这里的格式，格式问题典型！输出0的时候是输出0\n\n，写到备注里。