#pragma warning(disable: 4996)
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long toDecimal(char N[11], int radix) {
	if (radix == 10) return atoll(N);
	//char digits[11];
	//sprintf(digits, "%lld", N);
	long long decimal = 0;
	for (long long i = strlen(N) - 1, product = 1; i >= 0; i--, product *= radix) {//product乘积
		if (N[i] >= '0' && N[i] <= '9')
			decimal += (N[i] - '0') * product;
		else if (N[i] >= 'a' && N[i] <= 'z')
			decimal += (N[i] - 'a' + 10) * product;
	}
	return decimal;
}

long long binarySearch(long long left, long long right, long long value, char N[11]) {//找到第一个符合value的位置
	long long mid;
	long long decimal;
	while (left <= right) {//这一段代码的各种形式整理到笔记里
		mid = (left + right) / 2;
		decimal = toDecimal(N, mid);
		if (decimal == value) return mid;
		else if (decimal > value || decimal < 0) right = mid - 1;//如果是递减直接把>改成<，加<0判断溢出
		else left = mid + 1;
	}
	return -1;
}

int main(int argc, char *argv[]) {
	char N[3][11];
	int tag, radix;
	long long Nn[3];//十进制
	scanf("%s %s %d %d", N[1], N[2], &tag, &radix);
	if (strcmp(N[1], N[2]) == 0) printf("%d", radix);
	else {
		Nn[tag] = toDecimal(N[tag], radix);
		long long nin = 0, nax;//最小的数位，N[3 - tag]的最小进制是这个最小数位加一
		for (int i = 0; i < strlen(N[3 - tag]); i++)
			if (N[3 - tag][i] >= 'a')
				if (nin < N[3 - tag][i] - 'a' + 10)
					nin = N[3 - tag][i] - 'a' + 10;
				else;
			else
				if (nin < N[3 - tag][i] - '0')
					nin = N[3 - tag][i] - '0';
		nin = nin + 1;
		nax = (nin > Nn[tag] ? nin : Nn[tag]) + 1;
		long long answer = binarySearch(nin, nax, Nn[tag], N[3 - tag]);
		answer == -1 ? printf("Impossible") : printf("%lld", answer);
	}
	system("pause");
	return 0;
}
//最高只能是36进制，1位数只有0 ~ z这36个字符来表示，如果需要更高进制，那得用ASCII里的其他字符来凑。
//艹，这题，可以大于36进制，那恕我直言，一进制呢？
//一进制其实就是堆叠同一个数字来计数，比如我用0来计，100就可以表示为000...0（100位），用1来计，10就可以表示为1111111111。
//一开始测试点错了一半，我left和right完全想错了，虽然没有超时但很容易溢出，如果按正确的left和right思路的话，这题不错。
//最后如果有测试点不对的话，只管把所有涉及到答案的数据检查一遍是否是long long int即可。