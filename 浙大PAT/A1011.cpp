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
		else//赔率应该不会相等吧
			if (t < l) {
				game[i] = l;
				printf("L ");
			}
			else {//tie的两种情况都在这里
				game[i] = t;
				printf("T ");
			}
	}
	profit = profit * (game[0] * game[1] * game[2] * 0.65 - 1);
	printf("%.2lf", profit);
	system("pause");
	return 0;
}
//过于简单了，十分钟写完
//书上的答案思路不太一样