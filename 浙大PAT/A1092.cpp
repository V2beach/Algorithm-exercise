#pragma warning(disable: 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int charToInteger(char c) {
	if (c >= 'a' && c <= 'z')
		return c - 'a';
	else if (c >= 'A' && c <= 'Z')
		return 26 + c - 'A';
	else if (c >= '0' && c <= '9')
		return 52 + c - '0';
	else return -1;
}

int main(int argc, char *argv[]) {
	int hashTable[62];
	memset(hashTable, 0, 62 * sizeof(int));
	char str1[1001], str2[1001];
	scanf("%s %s", str1, str2);
	int count = 0;
	for (int i = 0; i < strlen(str1); i++)
		hashTable[charToInteger(str1[i])]++;
	for (int i = 0; i < strlen(str2); i++) {
		if (hashTable[charToInteger(str2[i])] > 0) {
			hashTable[charToInteger(str2[i])]--;
			count++;
		}
	}
	if (count == strlen(str2))
		printf("Yes %d", strlen(str1) - count);
	else
		printf("No %d", strlen(str2) - count);
	system("pause");
	return 0;
}