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
	long long sqr = sqrt(N);//����һ���Լ����������ȡ����
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
	if (seqMax < 0) printf("%lld\n%lld", (long long)(1), N);//�������һ���ǵ��ж�
	else printf("%lld\n%lld", seqMax, seqFirst);
	for (long long i = 1; i < seqMax; i++) {
		printf("*%lld", seqFirst + i);
	}
	system("pause");
	return 0;
}
//��ע�������Ҿ�û�кܿ��뵽˼·���Ҿ�Ȼ�Ҳ���˼·�����Ӳ�ת�ˣ���ʵ�Ǹ��ܼ򵥵��뷨�����ֻ����������һ���֣�����˵����ֻ���������������ӣ�ֻ��Ҫ�������������ӡ�
//�������ϵĴ���֮������ף�����Ҫ��������������������ӵ����п��ܳ˻���ֻ��Ҫ������sqr��ÿ���㣬����������ͳ��Գ���������������Ϳ����ˡ�