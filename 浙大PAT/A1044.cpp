#pragma warning(disable: 4996)
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

long long binarySearch(long long* array, vector<long long*> &answer, long long left, long long right, long long value) {
	long long mid, *diamonds = new long long[2];
	diamonds[0] = left;
	while (left < right) {
		mid = (left + right) / 2;
		if (diamonds[0] == 0 && array[mid] >= value) right = mid;//��ֹԽ��
		else if (array[mid] - array[diamonds[0] - 1] >= value) right = mid;
		else left = mid + 1;
	}
	long long diff = diamonds[0] == 0 ? array[left] - value : array[left] - array[diamonds[0] - 1] - value;
	diamonds[0]++;
	diamonds[1] = left + 1;
	answer.push_back(diamonds);
	return diff;
}

int main(int argc, char *argv[]) {
	long long N, M;
	scanf("%lld %lld", &N, &M);
	long long *diamonds = new long long[N];
	long long sum = 0;
	for (long long i = 0; i < N; i++) {
		scanf("%lld", &diamonds[i]);
		sum += diamonds[i];
		diamonds[i] = sum;
	}
	vector<long long*> answer;
	long long *diff = new long long[N];
	long long minDiff = M;//��С�Ĳ�ֵ������������
	for (long long i = 0; i < N; i++) {
		diff[i] = binarySearch(diamonds, answer, i, N - 1, M);//���û�иպ���ȵľʹ浽��һ�������������λ�ã���¼ÿ�����кͽ��Ĳ�ֵ����û�����
		if (diff[i] >= 0 && minDiff > diff[i]) minDiff = diff[i];
	}
	for (long long i = 0; i < N; i++)
		if (minDiff == diff[i])
			printf("%lld-%lld\n", answer[i][0], answer[i][1]);
	system("pause");
	return 0;
}
//��ƪ����Ҫ���¶�����û�п����ϵ���⡣
//�㷨�ʼ������˼·�ǳ��򵥵��Ƿǳ�Ư����Ӧ��ѧϰ����˼·���ܰ�
//������5��7�ĺ���ʵ����sum[7] - sum[4]������ֻ��Ҫ��һ���ۼ�����