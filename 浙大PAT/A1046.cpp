#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);

	int *D = new int[N + 1];
	D[0] = 0;
	int sum = 0;
	for (int i = 1; i <= N; i++) {//让下标对齐比较好理解
		scanf("%d", &D[i]);
		sum += D[i];
		D[i] = sum;//是从1到i+1的总长度
	}

	int M;
	scanf("%d", &M);

	int Vi, Vj;
	int clockwise = 0, countercw = 0;//顺时针逆时针
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &Vi, &Vj);
		//shoDist(N, D, Vi, Vj);开始写了个shoDist函数计算，但是最后一个测试点总是超时，后来选择了书上的算法
		if (Vi > Vj)
			swap(Vi, Vj);
		clockwise = D[Vj - 1] - D[Vi - 1];
		countercw = sum - clockwise;
		printf("%d", clockwise < countercw ? clockwise : countercw);
		if (i != M - 1)
			printf("\n");
	}

	system("pause");
	return 0;
}