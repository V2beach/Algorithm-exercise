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
	for (int i = 1; i <= N; i++) {//���±����ȽϺ����
		scanf("%d", &D[i]);
		sum += D[i];
		D[i] = sum;//�Ǵ�1��i+1���ܳ���
	}

	int M;
	scanf("%d", &M);

	int Vi, Vj;
	int clockwise = 0, countercw = 0;//˳ʱ����ʱ��
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &Vi, &Vj);
		//shoDist(N, D, Vi, Vj);��ʼд�˸�shoDist�������㣬�������һ�����Ե����ǳ�ʱ������ѡ�������ϵ��㷨
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