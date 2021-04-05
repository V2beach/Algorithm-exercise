#pragma warning(disable: 4996)
#include <cstdio>
#include <algorithm>

using namespace std;

int nonIncreasing(int num) {
	char digits[5];
	sprintf(digits, "%04d", num);//�ʼǣ��Ժ�itoaȫ���ĳ�sprintf
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
	if (num == 6174) printf("7641 - 1467 = 6174");//����Ҫ��һ�����Ե㣬�ǵò��Ա߽����������
	while (num != 0 && num != 6174) {
		int a = nonIncreasing(num);
		int b = nonDecreasing(num);
		num = a - b;
		printf("%04d - %04d = %04d\n", a, b, num);
	}
	system("pause");
	return 0;
}
//��Hash��������ѧ��֮��˳�ŵݹ����д�����̫���꣬Ҫ��ס���������д������ɡ�
//�����뵽��������1ת�ַ�����2��λ����Ȼ���ĸ���������