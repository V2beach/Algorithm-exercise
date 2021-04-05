#pragma warning(disable: 4996)
#include <cstdio>
#include <algorithm>

using namespace std;

long long binarySearch(long long array[], long long left, long long right, long long val) {//���������ҵ��ǵ�һ������val��λ��
	long long mid;
	while (left < right) {//left == rightʱ�Ѿ��ҵ�λ����
		mid = (left + right) / 2;
		if (array[mid] > val)//������ܾ��ǵ�һ�����ڵ�λ��
			right = mid;
		else
			left = mid + 1;
	}
	return left;//��rightһ��
}

int main(int argc, char *argv[]) {//�Լ�дһ����Ȼ����㷨�ʼ��ϵĴ����˼·�Ա�һ�£�ȡ������
	long long N, p, length = -1;
	scanf("%lld %lld", &N, &p);
	long long *sequence = new long long[N];
	for (long long i = 0; i < N; i++)
		scanf("%lld", &sequence[i]);
	sort(sequence, sequence + N);
	for (long long i = 0; i < N; i++) {
		long long j = binarySearch(sequence, i, N, p * sequence[i]);
		if (j - i > length)
			length = j - i;
	}
	printf("%lld", length);
	system("pause");
	return 0;
}
//һ��AC����Ȼ����Ҫ���飡
//�㷨�ʼ�д��˼·����ϸ