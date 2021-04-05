#pragma warning(disable: 4996)
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Fraction {
	long up, down;
};

long gcd(long a, long b) {
	return b == 0 ? a : gcd(b, a % b);
}

void reduction(Fraction &a) {
	long gcdOfFraction = gcd(abs(a.up), a.down);//�����м����ط����Լ�abs�������Ӧ��ֻ�л����ʱ����Ҫ���ϣ�����С��Լ���������ӿ�����
	a.up /= gcdOfFraction;
	a.down /= gcdOfFraction;
}

Fraction add(Fraction a, Fraction b) {
	Fraction result;
	result.up = a.up * b.down + a.down * b.up;
	result.down = a.down * b.down;
	return result;
}

Fraction subtract(Fraction a, Fraction b) {
	Fraction result;
	result.up = a.up * b.down - a.down * b.up;
	result.down = a.down * b.down;
	return result;
}

Fraction multiply(Fraction a, Fraction b) {
	Fraction result;
	result.up = a.up * b.up;
	result.down = a.down * b.down;
	return result;
}

Fraction divide(Fraction a, Fraction b) {
	if (b.up < 0) { b.up = -b.up; b.down = -b.down; }
	Fraction result;
	result.up = a.up * b.down;
	result.down = a.down * b.up;
	return result;
}

int print(Fraction a) {//������ֵû������Ŀ����?:
	//1.����
	reduction(a);
	long integer = a.up / a.down;
	long up = a.up % a.down;
	long down = a.down;

	if (a.up < 0) printf("(");

	//2.����
	if (down == 1 || up == 0) printf("%ld", integer);
	//3.�ٷ���
	else if (integer != 0) printf("%ld %ld/%ld", integer, abs(up), down);//����ҲҪ��abs����A1081���Ե㲻ȫ��
	//4.�����
	else printf("%ld/%ld", up, down);

	if (a.up < 0) printf(")");
	return 0;
}

int main(int argc, char *argv[]) {
	Fraction a, b;//long�͹��ˣ�����ͨ�����в��Ե㣬����Ҳ������long long��
	scanf("%ld/%ld %ld/%ld", &a.up, &a.down, &b.up, &b.down);
	print(a); printf(" + "); print(b); printf(" = "); print(add(a, b)); printf("\n");
	print(a); printf(" - "); print(b); printf(" = "); print(subtract(a, b)); printf("\n");
	print(a); printf(" * "); print(b); printf(" = "); print(multiply(a, b)); printf("\n");
	print(a); printf(" / "); print(b); printf(" = "); b.up == 0 ? printf("Inf") : print(divide(a, b)); printf("\n");
	system("pause");
	return 0;
}
//�ǵõ���ģ�⿼�Ծ�д����һ����ܳ����Ҫ�ٷ�����ȥ�ˡ�
//����������⣬���Ƿǳ�ģ�廯�Ĳ�������Ҳ�кܶ�ϸ�ڱ��縺����ô������Ҫע�⣬�ǵ�����ʼǡ�