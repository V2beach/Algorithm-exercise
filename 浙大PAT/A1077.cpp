#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);
	char **niHonJin = new char*[N];//日本人和日语都是NiHonJin
	int *len = new int[N];
	getchar();//很怪，因为没法用gets，用gets_s读的时候会多读一个字符
	for (int i = 0; i < N; i++) {
		niHonJin[i] = new char[256];
		//gets_s(niHonJin[i], 300);//PAT的编译器不支持这个，我吐了
		//scanf("%[^\n]", niHonJin[i]);
		int j = 0;
		while (((niHonJin[i][j] = getchar()) != '\n'))//来了，最原始的读数据写法
			j++;
		if (j == 0) {//出现空字符串，但其实测试点没有这种情况，最后一个测试点到底是啥？
			printf("nai");
			system("pause");
			return 0;
		}
		niHonJin[i][j] = '\0';
		len[i] = strlen(niHonJin[i]);
	}
	char suffix[256];
	char buff;
	int suff = -1;
	int maxLen = *max_element(len, len + N);//algorithm
	for (int i = 1; i <= 256; i++) {
		buff = niHonJin[0][len[0] - i];
		for (int j = 0; j < N; j++) {
			if (buff == niHonJin[j][len[j] - i])
				continue;
			else
				suff = i - 1;
		}
		if (suff != -1)//这个判断条件要在上面，因为可能maxLen内的最后一位(也就是str[0])是不一样的
			break;
		if (i == maxLen) {//最后一个测试点是这样测出来的2 123456 123465
			suff = maxLen;
			break;
		}
	}
	//printf("%d", suff);//right
	strcpy(suffix, niHonJin[0] + len[0] - suff);
	if (suff == 0)
		printf("nai");
	else
		printf("%s", suffix);
	system("pause");
	return 0;
}
//书上思路是反转字符串，我也写一个试试看