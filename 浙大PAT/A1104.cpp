#pragma warning(disable: 4996)
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);
	double num;
	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += (long long)(num * 1000) * i * (N - i + 1);
	}
	printf("%.2f", sum / 1000.0);
	system("pause");
	return 0;
}
//���Ƿǳ������һ���⡣
//�������Լ��ǻ�û�ҳ������ɣ������ټ���