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
	long gcdOfFraction = gcd(abs(a.up), a.down);//到底有几个地方可以加abs记清楚，应该只有化简的时候需要加上（求最小公约数），不加可以吗？
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

int print(Fraction a) {//不返回值没法用三目运算?:
	//1.化简
	reduction(a);
	long integer = a.up / a.down;
	long up = a.up % a.down;
	long down = a.down;

	if (a.up < 0) printf("(");

	//2.整数
	if (down == 1 || up == 0) printf("%ld", integer);
	//3.假分数
	else if (integer != 0) printf("%ld %ld/%ld", integer, abs(up), down);//这里也要加abs啊，A1081测试点不全！
	//4.真分数
	else printf("%ld/%ld", up, down);

	if (a.up < 0) printf(")");
	return 0;
}

int main(int argc, char *argv[]) {
	Fraction a, b;//long就够了，足以通过所有测试点，本来也是想用long long的
	scanf("%ld/%ld %ld/%ld", &a.up, &a.down, &b.up, &b.down);
	print(a); printf(" + "); print(b); printf(" = "); print(add(a, b)); printf("\n");
	print(a); printf(" - "); print(b); printf(" = "); print(subtract(a, b)); printf("\n");
	print(a); printf(" * "); print(b); printf(" = "); print(multiply(a, b)); printf("\n");
	print(a); printf(" / "); print(b); printf(" = "); b.up == 0 ? printf("Inf") : print(divide(a, b)); printf("\n");
	system("pause");
	return 0;
}
//记得当初模拟考试就写了这一道，艹，不要再废物下去了。
//像分数这种题，就是非常模板化的操作，但也有很多细节比如负号怎么处理需要注意，记得整理笔记。