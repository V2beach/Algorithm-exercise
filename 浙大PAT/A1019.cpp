#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	int decimal, base, cursor = 0;//10->base
	scanf("%d %d", &decimal, &base);
	int result[6324];

	do {//这样存的数是反的
		result[cursor++] = decimal % base;
		decimal = decimal / base;
	} while (decimal != 0);

	//判断回文数，懒得放到一个函数里了
	bool flag = true;
	for (int i = 0; i < cursor; i++)
		if (result[i] != result[cursor - i - 1])
			flag = false;
	if (flag)
		printf("Yes\n");
	else
		printf("No\n");

	//打印
	for (int i = cursor - 1; i >= 0; i--) {
		printf("%d", result[i]);
		if (i != 0)
			printf(" ");
	}

	system("pause");
	return 0;
}
//10->base1的进制转换和书上的思路不完全一样，书上的做法我写到题目里了
//int main(int argc, char *argv[]) {
//	int decimal, base1, result1 = 0;//10->base1
//	scanf("%d %d", &decimal, &base1);
//	for (int i = decimal, j = 1; i != 0; j = j * 10) {
//		result1 = result1 + j * (i % base1);
//		i = i / base1;
//	}
//	printf("%d\n", result1);
//
//	int reverse, base2, result2 = 0;//base2->10
//	scanf("%d %d", &reverse, &base2);
//	for (int i = reverse, j = 1; i != 0; j = j * base2) {
//		result2 = result2 + j * (i % 10);
//		i = i / 10;
//	}
//	printf("%d", result2);
//
//	system("pause");
//	return 0;
//}