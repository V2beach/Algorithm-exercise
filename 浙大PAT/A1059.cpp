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
			for (long long j = i + 1; j <= limit; j++)//ɸ��������������б���
				if (j % i == 0) prime[j] = true;
		}
	return index;
}

int main(int argc, char *argv[]) {
	//1.�����ṹ���¼�������Լ����ִ���
	Factor *factors = new Factor[nax];//�������ô�һ�㣬����������
	bool prime[nax];
	memset(prime, false, nax * sizeof(bool));
	//2.ɸ���洢������
	long long N, fuck, shit = 0;
	scanf("%lld", &N);
	printf("%lld=", N);
	if (N == 1) printf("1");//�߽�������1��2147473647���֣���Ϊ��������û��1�����������ǿ���ֱ������ġ�
	long long sqr = sqrt(N);
	fuck = findPrime(factors, prime, sqr);
	//3.��1��sqrt(n)������ֻ����0��1������sqrt(n)������
	for (long long i = 0; i < fuck; i++) {
		if (N % factors[i].prime == 0) {
			N /= factors[i].prime;
			factors[i--].times++;//�ظ����������
			shit++;
		}
	}
	if (N > 1) {//���һ������
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
//��ע��ѧ����Ա߽���������Ҫ�����������ֵúܺã���ӡ�����������ܾ��䡣