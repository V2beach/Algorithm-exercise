#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
	char str[81];
	scanf("%s", str);
	int N = strlen(str) + 2;

	int n2 = int(ceil(N / 3.0));
	if ((N - n2) % 2 == 1)
		n2++;
	int n13 = (N - n2) / 2;
	char space[27];
	int i = 0, j = 0, k = 0;
	for (; i < n2 - 2; i++)
		space[i] = ' ';
	space[i] = '\0';
	for (; j < n13 - 1; j++)
		printf("%c%s%c\n", str[j], space, str[N - j - 3]);
	for (; k < n2; k++)
		printf("%c", str[k + j]);

	system("pause");
	return 0;
}
//多找几个测试点确保万无一失
//看一下书上的题解，思路不同