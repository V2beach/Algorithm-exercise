#pragma warning(disable: 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Bign {
	int digits[21], len;
	Bign() { memset(digits, -1, 21 * sizeof(int)); }
};

Bign doubleBign(Bign bign) {
	Bign fuck;
	fuck.len = bign.len;
	int shit = 0, pussy = 0;//进位和本位
	for (int i = 0; i < bign.len; i++) {
		pussy = bign.digits[i] * 2 + shit;
		shit = pussy / 10;
		fuck.digits[i] = pussy % 10;
	}
	if (shit > 0) fuck.digits[fuck.len++] = shit;
	return fuck;
}

bool areTheyTheSame(Bign a, Bign b) {
	int digitsa[10], digitsb[10];
	memset(digitsa, 0, 10 * sizeof(int));
	memset(digitsb, 0, 10 * sizeof(int));
	for (int i = 0; i < a.len; i++) {
		digitsa[a.digits[i]]++;
		digitsb[b.digits[i]]++;
	}
	for (int i = 0; i < 10; i++) {
		if (digitsa[i] != digitsb[i])
			return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
	char buff[21];
	scanf("%s", buff);
	Bign bign;//转换
	bign.len = strlen(buff);
	for (int i = 0; i < bign.len; i++) {
		bign.digits[i] = buff[bign.len - i - 1] - '0';
	}
	Bign doubled = doubleBign(bign);
	if (areTheyTheSame(doubled, bign)) printf("Yes\n");
	else printf("No\n");
	for (int i = 0; i < doubled.len; i++) {
		printf("%d", doubled.digits[doubled.len - i - 1]);
	}
	system("pause");
	return 0;
}
//大整数运算还是很好做的，只是需要注意测试各种特殊条件。