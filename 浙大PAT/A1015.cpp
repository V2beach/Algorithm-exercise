#pragma warning(disable: 4996)
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

long reverse(long fuck, int radix) {
	int shit[233], index = 0;
	while (fuck != 0) {
		shit[index++] = fuck % radix;
		fuck /= radix;
	}//不熟练的话，最好写出来看一下...
	for (int i = index - 1, product = 1; i >= 0; i--, product *= radix) {
		fuck += product * shit[i];
	}
	return fuck;
}

bool isPrime(long fuck) {
	if (fuck <= 1) return false;
	long sqr = long(sqrt(1.0 * fuck));
	for (long i = 2; i <= sqr; i++)
		if (fuck % i == 0)
			return false;
	return true;
}

int main(int argc, char *argv[]) {
	long prime;
	int radix;
	while (scanf("%ld", &prime) && prime > 0) {//scanf返回读数个数或者EOF，而只有0对应FALSE，所以while一定不会因为scanf这个函数停止循环
		scanf("%d", &radix);
		if (isPrime(prime) && isPrime(reverse(prime, radix))) printf("Yes\n");
		else printf("No\n");
	}
	system("pause");
	return 0;
}
//我被误导了...输入的数不一定是prime，不要忘记判断这个
//进制转换不熟练，写到备注里！
//下面是一开始的写法，是想刻意练一下进制转换的代码，没想到最后一个测试点总是不过，就换了正常写法
//#pragma warning(disable: 4996)
//#include <cmath>
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//long long toDecimal(long long fuck, long long radix) {
//	long long decimal = 0, product = 1;
//	while (fuck != 0) {
//		decimal += (fuck % 10) * product;
//		fuck /= 10;//去掉最低位
//		product *= radix;
//	}
//	return decimal;
//}
//
//long long toRadix(long long prime, long long radix) {
//	long long shit[123];
//	long long pussy = 0, index = 0;
//	while (prime != 0) {
//		shit[index++] = prime % radix;
//		prime /= radix;
//	}
//	for (long long i = 0, product = 1; i < index; i++, product *= 10)
//		pussy += product * shit[i];
//	return pussy;
//}
//
//long long reverse(long long fuck) {
//	char digits[321];
//	sprintf(digits, "%lld", fuck);
//	char rev[321];
//	long long len = strlen(digits);
//	for (long long i = 0; i < len; i++)
//		rev[i] = digits[len - i - 1];
//	return atoll(rev);
//}
//
//bool isPrime(long long fuck) {
//	if (fuck <= 1) return false;
//	long long sqr = long(sqrt(1.0 * fuck));
//	for (long long i = 2; i <= sqr; i++)
//		if (fuck % i == 0)
//			return false;
//	return true;
//}
//
//int main(long long argc, char *argv[]) {//复习一下c的动态数组alloc啥的
//	long long prime;
//	long long radix;
//	long long fuck = 32;
//	while (scanf("%lld", &prime) && prime > 0) {
//		scanf("%lld", &radix);
//		if (!isPrime(prime)) printf("No\n");
//		else if (radix == 10)
//			if (isPrime(reverse(prime)))
//				printf("Yes\n");
//			else printf("No\n");
//		else {
//			fuck = toRadix(prime, radix);
//			fuck = reverse(fuck);
//			fuck = toDecimal(fuck, radix);//把这步落下了...最好在做题之前写个手稿，而且这个题根本不用写出来两段进制转换的代码，是自己给自己找麻烦了
//										  //printf("%lld\n", fuck);
//			if (isPrime(fuck))
//				printf("Yes\n");
//			else printf("No\n");
//		}
//	}
//	system("pause");
//	return 0;
//}