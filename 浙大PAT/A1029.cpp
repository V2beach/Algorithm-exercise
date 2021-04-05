#pragma warning(disable: 4996)
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	//read
	long N1;
	scanf("%ld", &N1);
	long *N1s = new long[N1];
	for (long i = 0; i < N1; i++)
		scanf("%ld", &N1s[i]);
	long N2;
	scanf("%ld", &N2);
	long *N2s = new long[N2];
	for (long i = 0; i < N2; i++)
		scanf("%ld", &N2s[i]);
	//merge
	long *Ns = new long[N1 + N2];
	long median, i = 0, j = 0, index = 0;
	while (i < N1 && j < N2) {
		if (N1s[i] <= N2s[j]) Ns[index++] = N1s[i++];
		else Ns[index++] = N2s[j++];
	}
	while (i < N1) Ns[index++] = N1s[i++];
	while (j < N2) Ns[index++] = N2s[j++];
	median = Ns[long(ceil(index / 2.0)) - 1];//���ϲ��Ǻϲ������ģ��ϲ��Ļ�Ҫע��������±�
	//print
	printf("%ld", median);
	system("pause");
	return 0;
}
//���ʱ���ֺ����������index / 2��0 2 3 6 7���Ե�ͨ����index / 2 - 1��1 4 5 8���Ե�ͨ��