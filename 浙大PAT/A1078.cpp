#pragma warning(disable: 4996)
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool isPrime(int fuck) {
	if (fuck <= 1) return false;
	int sqr = sqrt(fuck);
	for (int i = 2; i <= sqr; i++)//<=
		if (fuck % i == 0)
			return false;
	return true;
}

int main(int argc, char *argv[]) {
	bool flag;
	int Msize, N, shit, pussy, nipple;
	scanf("%d %d", &Msize, &N);
	while (!isPrime(Msize++));
	Msize--;//�ҵ���һ������
	bool *hashTable = new bool[Msize];
	memset(hashTable, false, Msize * sizeof(bool));
	for (int i = 0; i < N; i++) {
		flag = true;//�Ҳ���λ�õ�����
		scanf("%d", &shit);
		pussy = shit % Msize;
		if (!hashTable[pussy]) {
			hashTable[pussy] = true;
			printf("%d", pussy);
		}
		else {
			for (int j = 1; j < Msize; j++) {
				nipple = (pussy + j * j) % Msize;
				if (!hashTable[nipple]) {
					flag = false;
					hashTable[nipple] = true;
					printf("%d", nipple);
					break;//���ﲻ�����������㲻����ѭ��Ҳһ���ᱨ��ʱ�Ĵ���һ��ע���Ż�ϸ��
				}
			}
			if (flag) printf("-");
		}
		if (i != N - 1) printf(" ");
	}
	system("pause");
	return 0;
}
//��ע����ʱ������̽�鷨�����ͻ�������ţ�����ݹ�ģ��������͸��뵽��һ�㡣