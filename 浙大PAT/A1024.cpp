#pragma warning(disable: 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
#define nax 233

using namespace std;

struct Bign {
	int digits[nax], len;
	Bign() { memset(digits, -1, nax * sizeof(int)); }
};

bool isit(Bign fuck) {//Is it a Palindromic Number?
	for (int i = 0; i <= fuck.len / 2; i++)
		if (fuck.digits[i] != fuck.digits[fuck.len - i - 1])
			return false;
	return true;
}

Bign reverse(Bign fuck) {
	Bign shit;
	shit.len = fuck.len;
	for (int i = 0; i < fuck.len; i++)
		shit.digits[i] = fuck.digits[fuck.len - i - 1];
	return shit;
}

Bign add(Bign a, Bign b) {
	Bign fuck;
	fuck.len = a.len;
	int shit = 0, pussy;//进位，本位
	for (int i = 0; i < a.len; i++) {
		pussy = a.digits[i] + b.digits[i] + shit;
		shit = pussy / 10;
		fuck.digits[i] = pussy % 10;
	}
	if (shit > 0) fuck.digits[fuck.len++] = shit;//倒序的
	return fuck;
}

void print(Bign holy) {
	for (int i = 0; i < holy.len; i++)
		printf("%d", holy.digits[holy.len - i - 1]);
}

int main(int argc, char *argv[]) {
	char buff[nax];
	int K, i;
	scanf("%s %d", buff, &K);
	Bign bign;
	bign.len = strlen(buff);
	for (i = 0; i < bign.len; i++) {
		bign.digits[i] = buff[bign.len - i - 1] - '0';
	}
	for (i = 0; i <= K; i++) {
		if (isit(bign) || i == K) {
			print(bign);
			printf("\n%d", i);
			break;
		}
		bign = add(bign, reverse(bign));
	}
	system("pause");
	return 0;
}
//别忘了回文数本身这种特殊情况，484 0！
//下面这种写法也是可以的
//#pragma warning(disable: 4996)
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#define nax 233
//
//using namespace std;
//
//struct Bign {
//	int digits[nax], len;
//	Bign() { memset(digits, -1, nax * sizeof(int)); }
//};
//
//bool isit(Bign fuck) {//Is it a Palindromic Number?
//	for (int i = 0; i <= fuck.len / 2; i++)
//		if (fuck.digits[i] != fuck.digits[fuck.len - i - 1])
//			return false;
//	return true;
//}
//
//Bign reverse(Bign fuck) {
//	Bign shit;
//	shit.len = fuck.len;
//	for (int i = 0; i < fuck.len; i++)
//		shit.digits[i] = fuck.digits[fuck.len - i - 1];
//	return shit;
//}
//
//Bign add(Bign a, Bign b) {
//	Bign fuck;
//	fuck.len = a.len;
//	int shit = 0, pussy;//进位，本位
//	for (int i = 0; i < a.len; i++) {
//		pussy = a.digits[i] + b.digits[i] + shit;
//		shit = pussy / 10;
//		fuck.digits[i] = pussy % 10;
//	}
//	if (shit > 0) fuck.digits[fuck.len++] = shit;//倒序的
//	return fuck;
//}
//
//void print(Bign holy) {
//	for (int i = 0; i < holy.len; i++)
//		printf("%d", holy.digits[holy.len - i - 1]);
//}
//
//int main(int argc, char *argv[]) {
//	char buff[nax];
//	int K, i;
//	scanf("%s %d", buff, &K);
//	Bign bign;
//	bign.len = strlen(buff);
//	for (i = 0; i < bign.len; i++) {
//		bign.digits[i] = buff[bign.len - i - 1] - '0';
//	}
//	if (isit(bign)) {
//		print(bign);
//		printf("\n0");
//		system("pause");
//		return 0;
//	}
//	for (i = 0; i < K; i++) {
//		bign = add(bign, reverse(bign));
//		if (isit(bign)) {
//			print(bign);
//			printf("\n%d", i + 1);
//			break;
//		}
//	}
//	if (i >= K) {//break不会加到K
//		print(bign);
//		printf("\n%d", i);
//	}
//	system("pause");
//	return 0;
//}