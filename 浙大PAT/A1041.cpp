#pragma warning(disable: 4996)
#include <cstdio>
#include <cstring>

using namespace std;

//���ֱ����map�أ�
int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);
	int hashTable[10001];//����һ����ϣ���¼���ֵĳ��ִ���֮��
	memset(hashTable, 0, 10001 * sizeof(int));
	int numbers[100001];//��Ҫһ�������¼�ֱ���ֵ���ʲô���֣���������ȷʵ�ȽϿ�
	for (int i = 0; i < N; i++) {
		scanf("%d", &numbers[i]);
		hashTable[numbers[i]]++;
	}
	int answer = -1;
	for (int i = 0; i < N; i++) {
		if (hashTable[numbers[i]] == 1) {
			answer = numbers[i];
			break;
		}
	}
	answer == -1 ? printf("None") : printf("%d", answer);
	system("pause");
	return 0;
}