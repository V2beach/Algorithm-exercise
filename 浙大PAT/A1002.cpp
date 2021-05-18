#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
	int K1;
	scanf("%d", &K1);
	K1 = 2 * K1;
	double *N1 = new double[K1 + 1];
	for (int i = 1; i <= K1; i++)
		scanf("%lf", &N1[i]);

	int K2;
	scanf("%d", &K2);
	K2 = 2 * K2;
	double *N2 = new double[K2 + 1];
	for (int i = 1; i <= K2; i++)
		scanf("%lf", &N2[i]);

	double *N3 = new double[K1 + K2];
	int i = 1, j = 1, k = 0;//三个数组的下标
	int zhishu;
	double xishu;

	bool flag = false;//多余的量

	for (; i <= K1; i = i + 2) {
		zhishu = N1[i];
		while (zhishu <= int(N2[j]) && j < K2) {
			if (int(N1[i]) == int(N2[j])) {//N1+N2->N3
				xishu = N1[i + 1] + N2[j + 1];

				if (fabs(xishu) > 1e-6) {
					N3[k] = zhishu;
					N3[k + 1] = xishu;
					k = k + 2;
				}
				flag = true;

			}
			else {//N2->N3

				if (fabs(N2[j + 1]) > 1e-6) {
					N3[k] = int(N2[j]);
					N3[k + 1] = N2[j + 1];
					k = k + 2;
				}
				flag = false;

			}
			j = j + 2;
		}
		if (!flag) {//N1->N3

			if (fabs(N1[i + 1]) > 1e-6) {
				N3[k] = zhishu;
				N3[k + 1] = N1[i + 1];
				k = k + 2;
			}

		}
		if (i > K1 - 2 && j < K2) {//N2->N3
			while (j < K2) {

				if (fabs(N2[j + 1]) > 1e-6) {
					N3[k] = int(N2[j]);
					N3[k + 1] = N2[j + 1];
					j = j + 2;
					k = k + 2;
				}

			}
		}
		if (j > K2) {
			i = i + 2;
			break;
		}
	}
	while (i < K1) {//N1->N3

		if (fabs(N1[i + 1]) > 1e-6) {
			N3[k] = int(N1[i]);
			N3[k + 1] = N1[i + 1];
			i = i + 2;
			k = k + 2;
		}

	}

	printf("%d", k / 2);
	for (i = 0; i < k; i = i + 2) {
		printf(" %d %.1lf", int(N3[i]), N3[i + 1]);
	}

	system("pause");
	return 0;
}
//我一开始是想用指数作为数组下标，那样会非常简单，参考答案的思路也都是如此，但我想让这个代码支持计算double指数，尝试增加了点难度
//测试点提示：没记错的话4/5是指数为0，6是结果只有一个0，0和2较简单，1和3卡了我最久，是逻辑上的错误，我用的测试数据是
/*
1 1000 0.7
5 1075 0.3 1000 -0.6 4 0.7 3 0.2 2 0.1
*/
//我一开始以为是没考虑到大指数，其实是当数组1算完了，数组2还有值的情况没考虑全，完全调通看到测试点全红的一刻简直爽爆
//好像各大OJ只有CF和TC会给测试数据，“不给测试数据更能锻炼思维的严谨性”，刚开始做的时候不太理解为什么从来看不到测试点信息，
//“对于一个oj来说，最值钱的不是这个系统，而是每道题的测试数据。”现在的我深以为然，另外，我这里也不提供简单版本的题解了
//因为下一道题，多项式乘法（这道题是多项式加法）我会用那种做法。