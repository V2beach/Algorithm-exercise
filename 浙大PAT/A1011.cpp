#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	double game[3];
	double w, t, l;
	double profit = 2;
	for (int i = 0; i < 3; i++) {
		scanf("%lf %lf %lf", &w, &t, &l);
		if (w > t)
			if (t > l) {
				game[i] = w;
				printf("W ");
			}
			else
				if (w < l) {
					game[i] = l;
					printf("L ");
				}
				else {
					game[i] = w;
					printf("W ");
				}
		else//����Ӧ�ò�����Ȱ�
			if (t < l) {
				game[i] = l;
				printf("L ");
			}
			else {//tie�����������������
				game[i] = t;
				printf("T ");
			}
	}
	profit = profit * (game[0] * game[1] * game[2] * 0.65 - 1);
	printf("%.2lf", profit);
	system("pause");
	return 0;
}
//���ڼ��ˣ�ʮ����д��
//���ϵĴ�˼·��̫һ��