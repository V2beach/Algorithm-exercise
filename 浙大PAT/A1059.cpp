#pragma warning(disable: 4996)
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define nax 123456

using namespace std;

struct Factor {
	long long prime, times;
	Factor() { prime = -1, times = 0; }
};

long long findPrime(Factor* &factors, bool prime[nax], long long limit) {
	long long index = 0;
	for (long long i = 2; i <= limit; i++)
		if (!prime[i]) {
			prime[i] = true;
			factors[index++].prime = i;
			for (long long j = i + 1; j <= limit; j++)//筛掉这个质数的所有倍数
				if (j % i == 0) prime[j] = true;
		}
	return index;
}

int main(int argc, char *argv[]) {
	//1.构建结构体记录质因子以及出现次数
	Factor *factors = new Factor[nax];//尽量开得大一点，后面再修正
	bool prime[nax];
	memset(prime, false, nax * sizeof(bool));
	//2.筛法存储素数表
	long long N, fuck, shit = 0;
	scanf("%lld", &N);
	printf("%lld=", N);
	if (N == 1) printf("1");//边界条件！1和2147473647这种，因为质数表里没有1，其他质数是可以直接输出的。
	long long sqr = sqrt(N);
	fuck = findPrime(factors, prime, sqr);
	//3.从1→sqrt(n)遍历，只会有0→1个大于sqrt(n)的因子
	for (long long i = 0; i < fuck; i++) {
		if (N % factors[i].prime == 0) {
			N /= factors[i].prime;
			factors[i--].times++;//重复测试这个数
			shit++;
		}
	}
	if (N > 1) {//最后一个因子
		factors[fuck].prime = N;
		factors[fuck++].times++;
	}
	for (long long i = 0; i < fuck; i++) {
		if (factors[i].times > 0) {
			printf("%lld", factors[i].prime);
			//factors[i--].times--;
			//shit--;
			if (factors[i].times > 1)
				printf("^%lld", factors[i].times);
			shit -= factors[i].times;
			if (shit > 0) printf("*");
		}
	}
	system("pause");
	return 0;
}
//备注，学会测试边界条件的重要性在这题体现得很好，打印质因子这个题很经典。