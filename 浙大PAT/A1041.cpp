#pragma warning(disable: 4996)
#include <cstdio>
#include <cstring>

using namespace std;

//如果直接用map呢？
int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);
	int hashTable[10001];//除了一个哈希表记录数字的出现次数之外
	memset(hashTable, 0, 10001 * sizeof(int));
	int numbers[100001];//需要一个数组记录分别出现的是什么数字，这样遍历确实比较快
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