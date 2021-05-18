#pragma warning(disable: 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(char* a, char* b) {
	return strcmp(a, b) < 0;
}

int main(int argc, char *argv[]) {
	int N, K;
	scanf("%d %d", &N, &K);
	vector<char*> *result = new vector<char*>[K + 1];//越界每次编译器报错不一样，这次居然没看出来...
	int courses, no;
	for (int i = 0; i < N; i++) {
		char *name = new char[5];//这个要放到里面，可以移出去对比一下区别加深理解，这个vector存的是地址，指针，如果放在外面就相当于自始至终只申请了一片空间，结果里所有人的name都会是一样的。
		scanf("%s %d", name, &courses);
		for (int j = 0; j < courses; j++) {
			scanf("%d", &no);
			result[no].push_back(name);
		}
	}
	for (int i = 1; i <= K; i++) {
		printf("%d %d\n", i, result[i].size());
		sort(result[i].begin(), result[i].end(), cmp);
		for (int j = 0; j < result[i].size(); j++)
			printf("%s\n", result[i][j]);
	}
	system("pause");
	return 0;
}
//思路和晴神柳婼完全一样，果然是这类题太简单了...还是发现了一些理解上的问题，在注释里写到了。