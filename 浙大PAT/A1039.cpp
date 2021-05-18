#pragma warning(disable: 4996)
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int nax = 26 * 26 * 26 * 10 + 1;
vector<int> result[nax];//？？？把这个当成全局变量就不会爆栈了...这段也不能放在namespace上面，理解一下？

int hashFunc(char name[5]) {
	//int hashValue = (name[0] - 'A' + 1) * (name[1] - 'A' + 1) * (name[2] - 'A' + 1) * (name[3] - '0' + 1);
	//像上面那样写，在这个题里还是会重，体会一下这个哈希算法，备注
	int hashValue = 0;
	for (int i = 0; i < 3; i++)
		hashValue = 26 * hashValue + name[i] - 'A';
	hashValue = 10 * hashValue + name[3] - '0';
	return hashValue;
}

int main(int argc, char *argv[]) {
	int N, K;
	scanf("%d %d", &N, &K);
	int course, students;
	char name[5];
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &course, &students);
		for (int j = 0; j < students; j++) {
			scanf("%s", name);
			result[hashFunc(name)].push_back(course);
		}
	}
	int hash;
	for (int i = 0; i < N; i++) {
		scanf("%s", name);
		hash = hashFunc(name);
		sort(result[hash].begin(), result[hash].end());
		printf("%s ", name);
		printf("%d", result[hash].size());//result[hash].empty() ? printf("0") : 不需要
		for (int j = 0; j < result[hash].size(); j++)
			printf(" %d", result[hash][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}
//思路正确，一次过，做出来的几乎和晴神和柳婼完全一样，hashFunc不一样。
//果然是要在做题前/做事前先在草稿纸上整理好思路！很重要！要养成这个习惯！！！
//1.不带手机；2.写代码前做完整的思路草稿。
//备注，这个题要好好地整理。