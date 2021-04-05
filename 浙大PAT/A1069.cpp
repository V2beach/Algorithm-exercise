#pragma warning(disable: 4996)
#include <cstdio>
#include <algorithm>

using namespace std;

int nonIncreasing(int num) {
	char digits[5];
	sprintf(digits, "%04d", num);//笔记：以后itoa全部改成sprintf
	sort(digits, digits + 4);
	return (digits[3] - '0') * 1000 + (digits[2] - '0') * 100 + (digits[1] - '0') * 10 + (digits[0] - '0');
}

int nonDecreasing(int num) {
	char digits[5];
	sprintf(digits, "%04d", num);
	sort(digits, digits + 4);
	return (digits[0] - '0') * 1000 + (digits[1] - '0') * 100 + (digits[2] - '0') * 10 + (digits[3] - '0');
}

int main(int argc, char *argv[]) {
	int num;
	scanf("%d", &num);
	if (num == 6174) printf("7641 - 1467 = 6174");//很重要的一个测试点，记得测试边界和特殊条件
	while (num != 0 && num != 6174) {
		int a = nonIncreasing(num);
		int b = nonDecreasing(num);
		num = a - b;
		printf("%04d - %04d = %04d\n", a, b, num);
	}
	system("pause");
	return 0;
}
//从Hash跳到简单数学，之后顺着递归继续写，最近太浮躁，要沉住气，今天就写完这道吧。
//我能想到的做法，1转字符串，2逐位除，然后四个数字排序。