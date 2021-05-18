#pragma warning(disable: 4996)
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	long long N, pussy, seqFirst = -1, seqLength = -1, seqMax = -1;
	scanf("%lld", &N);
	long long sqr = sqrt(N);//提醒一下自己这个是向下取整的
	for (long long i = 2; i <= sqr; i++) {
		pussy = N;
		seqLength = 0;
		if (pussy % i == 0) {
			pussy /= i;
			seqLength++;
			for (long long j = i + 1; j <= sqr; j++) {
				if (pussy % j == 0)
					pussy /= j;
				else break;
				seqLength++;
			}
			if (seqLength > seqMax) {
				seqMax = seqLength;
				seqFirst = i;
			}
		}
	}
	if (seqMax < 0) printf("%lld\n%lld", (long long)(1), N);//特殊情况一定记得判断
	else printf("%lld\n%lld", seqMax, seqFirst);
	for (long long i = 1; i < seqMax; i++) {
		printf("*%lld", seqFirst + i);
	}
	system("pause");
	return 0;
}
//备注，这题我竟没有很快想到思路，我居然找不到思路？脑子不转了，其实是个很简单的想法，求的只是连续的那一部分，或者说——只是求三个连续因子！只需要求三个连续因子。
//看了书上的代码之后才明白，不需要遍历出这个数的所有因子的所有可能乘积，只需要遍历到sqr的每个点，如果能整除就尝试除这个数的连续数就可以了。