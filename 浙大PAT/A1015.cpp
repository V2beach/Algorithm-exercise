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
	}//�������Ļ������д������һ��...
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
	while (scanf("%ld", &prime) && prime > 0) {//scanf���ض�����������EOF����ֻ��0��ӦFALSE������whileһ��������Ϊscanf�������ֹͣѭ��
		scanf("%d", &radix);
		if (isPrime(prime) && isPrime(reverse(prime, radix))) printf("Yes\n");
		else printf("No\n");
	}
	system("pause");
	return 0;
}
//�ұ�����...���������һ����prime����Ҫ�����ж����
//����ת����������д����ע�
//������һ��ʼ��д�������������һ�½���ת���Ĵ��룬û�뵽���һ�����Ե����ǲ������ͻ�������д��
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
//		fuck /= 10;//ȥ�����λ
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
//int main(long long argc, char *argv[]) {//��ϰһ��c�Ķ�̬����allocɶ��
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
//			fuck = toDecimal(fuck, radix);//���ⲽ������...���������֮ǰд���ָ壬����������������д�������ν���ת���Ĵ��룬���Լ����Լ����鷳��
//										  //printf("%lld\n", fuck);
//			if (isPrime(fuck))
//				printf("Yes\n");
//			else printf("No\n");
//		}
//	}
//	system("pause");
//	return 0;
//}