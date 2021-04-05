#pragma warning(disable: 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
//2020-08-29-19:56 start
using namespace std;

struct ZiBenJia {
	char name[9];
	int age;
	long money;
};

bool cmp(ZiBenJia a, ZiBenJia b) {
	if (a.money != b.money) return a.money > b.money;
	else if (a.age != b.age) return a.age < b.age;
	else {
		int c = strcmp(a.name, b.name);
		return c < 0;
	}
}

int main(int argc, char *argv[]) {
	long N;
	int K;
	scanf("%ld %d", &N, &K);
	ZiBenJia *bitches = new ZiBenJia[N];
	vector<vector<ZiBenJia>> forbes(K);
	for (int i = 0; i < N; i++)
		scanf("%s %d %ld", bitches[i].name, &bitches[i].age, &bitches[i].money);
	sort(bitches, bitches + N, cmp);

	int **queries = new int*[K];
	for (int i = 0; i < K; i++) {
		queries[i] = new int[3];
		scanf("%d %d %d", &queries[i][0], &queries[i][1], &queries[i][2]);
	}

	for (int i = 0; i < K; i++) {
		int j = 0, k = 0;
		while (j < queries[i][0] && k < N) {
			if (bitches[k].age >= queries[i][1] && bitches[k].age <= queries[i][2]) {
				forbes[i].push_back(bitches[k]);
				j++;
			}
			k++;
		}
	}

	for (int i = 0; i < K; i++) {
		printf("Case #%d:\n", i + 1);
		for (int j = 0; j < forbes[i].size(); j++)
			printf("%s %d %ld\n", forbes[i][j].name, forbes[i][j].age, forbes[i][j].money);
		if (forbes[i].size() == 0)
			printf("None\n");
	}

	system("pause");
	return 0;
}
//2020-08-29-20:29 finish
//看了十分钟IG vs FPX，竞争世界赛门票
//没错，这就是我辣鸡的学习状态