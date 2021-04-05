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
	Msize--;//找到第一个素数
	bool *hashTable = new bool[Msize];
	memset(hashTable, false, Msize * sizeof(bool));
	for (int i = 0; i < N; i++) {
		flag = true;//找不到位置的旗帜
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
					break;//这里不跳出来，就算不是死循环也一定会报超时的错误，一定注意优化细节
				}
			}
			if (flag) printf("-");
		}
		if (i != N - 1) printf(" ");
	}
	system("pause");
	return 0;
}
//备注，超时！二次探查法解决冲突那里，看到牛客数据规模大的用例就该想到这一点。