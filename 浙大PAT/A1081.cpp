#pragma warning(disable: 4996)
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Fraction {
	long up, down;
	Fraction() {}
	Fraction(long up, long down) { this->up = up; this->down = down; }
};

Fraction add(Fraction a, Fraction b) {
	Fraction result;
	result.up = a.up * b.down + a.down * b.up;
	result.down = a.down * b.down;
	return result;
}

long gcd(long a, long b) {//ˬ
	return b == 0 ? a : gcd(b, a % b);
}

void reduction(Fraction &a) {
	long gcdOfFraction = gcd(abs(a.up), a.down);
	a.up /= gcdOfFraction;
	a.down /= gcdOfFraction;
}

void print(Fraction a) {
	//1.����
	reduction(a);
	long integer = a.up / a.down;
	long up = a.up % a.down;//abs������
	long down = a.down;
	//2.����
	if (down == 1 || up == 0) printf("%ld", integer);
	//3.�ٷ���
	else if (integer != 0) printf("%ld %ld/%ld", integer, up, down);
	//4.�����
	else printf("%ld/%ld", up, down);
}

int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);
	Fraction fraction, sum(0, 1);
	for (int i = 0; i < N; i++) {
		scanf("%ld/%ld", &fraction.up, &fraction.down);
		sum = add(sum, fraction);
		reduction(sum);//��������������������Ҫ��һ��
	}
	print(sum);
	system("pause");
	return 0;
}