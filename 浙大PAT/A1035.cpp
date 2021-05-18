#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	int N, M = 0;
	scanf("%d", &N);
	char **username = new char*[N];
	char **password = new char*[N];
	int *modified = new int[N]();//不加括号不会初始化！差点忘了，记到笔记里
	//printf("%d",modified[0]);
	for (int i = 0; i < N; i++) {
		username[i] = new char[10];
		password[i] = new char[10];
		scanf("%s %s", username[i], password[i]);
		for (int j = 0; j < strlen(password[i]); j++)
			if (password[i][j] == '1') {
				password[i][j] = '@';
				modified[i] = 1;
			}
			else if (password[i][j] == 'l') {
				password[i][j] = 'L';
				modified[i] = 1;
			}
			else if (password[i][j] == '0') {
				password[i][j] = '%';
				modified[i] = 1;
			}
			else if (password[i][j] == 'O') {
				password[i][j] = 'o';
				modified[i] = 1;
			}
	}
	for (int i = 0; i < N; i++)
		if (modified[i] == 1)
			M++;
	if (M == 0)
		if (N == 1)
			printf("There is 1 account and no account is modified");
		else
			printf("There are %d accounts and no account is modified", N);
	else {
		printf("%d", M);
		for (int i = 0; i < N; i++)
			if (modified[i] == 1)
				printf("\n%s %s", username[i], password[i]);
	}
	system("pause");
	return 0;
}
//过于简单了，但柳婼用的是set，比我的效率高，学习一个