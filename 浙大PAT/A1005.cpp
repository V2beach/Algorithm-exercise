#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	int sum = 0;
	//while (scanf("%1d", &digit) != EOF)不好使
	char buffer[101];
	scanf("%s", buffer);
	for (int i = 0; i < strlen(buffer); i++)
		sum += buffer[i] - '0';
	char num[10][7] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	sprintf(buffer, "%d", sum);
	printf("%s", num[buffer[0] - '0']);
	for (int i = 1; i < strlen(buffer); i++)
		printf(" %s", num[buffer[i] - '0']);
		/*if (i != strlen(buffer) - 1)
			printf(" ");这样判断会慢一点*/
	system("pause");
	return 0;
}