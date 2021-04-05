#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

struct Poly {
	int zhishu;
	double xishu;
};

int main(int argc, char *argv[]) {
	int K1;
	scanf("%d", &K1);
	Poly *N1 = new Poly[K1];
	for (int i = 0; i < K1; i++)
		scanf("%d %lf", &N1[i].zhishu, &N1[i].xishu);

	int K2;
	scanf("%d", &K2);
	double *result = new double[2001]();//结果数组，下标为指数，指数最大值为2000，值为系数，带()及调用构造函数初始化为0.0
	//memset为什么不行？

	int zhishu;
	double xishu;
	int count = 0;

	for (int i = 0; i < K2; i++) {//一边读一边算
		scanf("%d %lf", &zhishu, &xishu);
		for (int j = 0; j < K1; j++) {
			if (fabs(result[zhishu + N1[j].zhishu]) <1e-6)
				count++;
			result[zhishu + N1[j].zhishu] += xishu * N1[j].xishu;
			if (fabs(result[zhishu + N1[j].zhishu]) < 1e-6)
				count--;
		}
	}

	if (count != 0) {
		printf("%d", count);
		for (int i = 2000; i >= 0; i--)
			if (fabs(result[i]) > 1e-6)
				printf(" %d %.1lf", i, result[i]);
	}
	else
		printf("0");

	system("pause");
	return 0;
}
//十几分钟完工，何必像A1002一样难为自己呢:/
//记录一下思路