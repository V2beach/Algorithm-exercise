#pragma warning(disable: 4996)
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int charToInteger(char c) {//哈希函数
	return int(c);
}

int main(int argc, char *argv[]) {
	bool hashTable[256];
	memset(hashTable, false, 256 * sizeof(bool));
	char str1[12345], str2[12345];
	cin.getline(str1, 12345, '\n');//getline(cin, str1, '\n');
	cin.getline(str2, 12345, '\n');
	for (int i = 0; i < strlen(str2); i++)
		hashTable[charToInteger(str2[i])] = true;
	for (int i = 0; i < strlen(str1); i++) {
		if (!hashTable[charToInteger(str1[i])])
			printf("%c", str1[i]);
	}
	system("pause");
	return 0;
}