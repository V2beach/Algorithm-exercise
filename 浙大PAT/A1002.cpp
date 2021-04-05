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
	int i = 1, j = 1, k = 0;//����������±�
	int zhishu;
	double xishu;

	bool flag = false;//�������

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
//��һ��ʼ������ָ����Ϊ�����±꣬������ǳ��򵥣��ο��𰸵�˼·Ҳ������ˣ����������������֧�ּ���doubleָ�������������˵��Ѷ�
//���Ե���ʾ��û�Ǵ�Ļ�4/5��ָ��Ϊ0��6�ǽ��ֻ��һ��0��0��2�ϼ򵥣�1��3��������ã����߼��ϵĴ������õĲ���������
/*
1 1000 0.7
5 1075 0.3 1000 -0.6 4 0.7 3 0.2 2 0.1
*/
//��һ��ʼ��Ϊ��û���ǵ���ָ������ʵ�ǵ�����1�����ˣ�����2����ֵ�����û����ȫ����ȫ��ͨ�������Ե�ȫ���һ�̼�ֱˬ��
//�������OJֻ��CF��TC����������ݣ��������������ݸ��ܶ���˼ά���Ͻ��ԡ����տ�ʼ����ʱ��̫���Ϊʲô�������������Ե���Ϣ��
//������һ��oj��˵����ֵǮ�Ĳ������ϵͳ������ÿ����Ĳ������ݡ������ڵ�������ΪȻ�����⣬������Ҳ���ṩ�򵥰汾�������
//��Ϊ��һ���⣬����ʽ�˷���������Ƕ���ʽ�ӷ����һ�������������