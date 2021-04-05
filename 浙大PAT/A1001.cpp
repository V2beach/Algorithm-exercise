#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	long a, b;
	scanf("%ld %ld", &a, &b);
	char c[15];
	sprintf(c, "%d", a + b);
	int len = strlen(c);
	for (int i = 0; i < len; i++) {
		printf("%c", c[i]);
		if (c[i] == '-') continue;
		if (i % 3 == (len - 1) % 3 && i != len - 1) printf(",");
	}
	system("pause");
	return 0;
}