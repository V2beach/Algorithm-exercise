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
	for (long long i = strlen(N) - 1, product = 1; i >= 0; i--, product *= radix) {//product�˻�
		if (N[i] >= '0' && N[i] <= '9')
			decimal += (N[i] - '0') * product;
		else if (N[i] >= 'a' && N[i] <= 'z')
			decimal += (N[i] - 'a' + 10) * product;
	}
	return decimal;
}

long long binarySearch(long long left, long long right, long long value, char N[11]) {//�ҵ���һ������value��λ��
	long long mid;
	long long decimal;
	while (left <= right) {//��һ�δ���ĸ�����ʽ�����ʼ���
		mid = (left + right) / 2;
		decimal = toDecimal(N, mid);
		if (decimal == value) return mid;
		else if (decimal > value || decimal < 0) right = mid - 1;//����ǵݼ�ֱ�Ӱ�>�ĳ�<����<0�ж����
		else left = mid + 1;
	}
	return -1;
}

int main(int argc, char *argv[]) {
	char N[3][11];
	int tag, radix;
	long long Nn[3];//ʮ����
	scanf("%s %s %d %d", N[1], N[2], &tag, &radix);
	if (strcmp(N[1], N[2]) == 0) printf("%d", radix);
	else {
		Nn[tag] = toDecimal(N[tag], radix);
		long long nin = 0, nax;//��С����λ��N[3 - tag]����С�����������С��λ��һ
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
//���ֻ����36���ƣ�1λ��ֻ��0 ~ z��36���ַ�����ʾ�������Ҫ���߽��ƣ��ǵ���ASCII��������ַ����ա�
//ܳ�����⣬���Դ���36���ƣ���ˡ��ֱ�ԣ�һ�����أ�
//һ������ʵ���Ƕѵ�ͬһ����������������������0���ƣ�100�Ϳ��Ա�ʾΪ000...0��100λ������1���ƣ�10�Ϳ��Ա�ʾΪ1111111111��
//һ��ʼ���Ե����һ�룬��left��right��ȫ����ˣ���Ȼû�г�ʱ��������������������ȷ��left��right˼·�Ļ������ⲻ��
//�������в��Ե㲻�ԵĻ���ֻ�ܰ������漰���𰸵����ݼ��һ���Ƿ���long long int���ɡ�