#pragma warning(disable: 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int charToInteger(char c) {
	if (c >= 'a' && c <= 'z')
		return c - 'a';
	else if (c >= 'A' && c <= 'Z')
		return c - 'A';
	else if (c >= '0' && c <= '9')
		return 26 + c - '0';
	else return 36;
}

int main(int argc, char *argv[]) {//思路，参考书上的办法，26个字母和10个数字加一个空格，字符集一共37个字符
	bool hashTable[37];
	memset(hashTable, false, 37 * sizeof(bool));
	char str1[81], str2[81];
	scanf("%s %s", str1, str2);
	for (int i = 0; i < strlen(str2); i++)
		hashTable[charToInteger(str2[i])] = true;
	for (int i = 0; i < strlen(str1); i++) {
		if (!hashTable[charToInteger(str1[i])]) {
			if (str1[i] >= 'a' && str1[i] <= 'z')
				printf("%c", str1[i] - 'a' + 'A');
			else
				printf("%c", str1[i]);
			hashTable[charToInteger(str1[i])] = true;
		}
		else;
	}
	system("pause");
	return 0;
}