#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

//这题看到9999Bytes这个数量级，就一定用字符串存了
int main(int argc, char*argv[]) {
	int zhishu;
	char zhengfu, zhengshu[20000], xiaoshu[20000];//要开到两倍于9999B
	char buffer[20000];
	scanf("%s", buffer);
	//itoa atoi?
	//scanf("%c%s.%sE%d", &zhengfu, zhengshu, xiaoshu, &zhishu);
	zhengfu = buffer[0];
	int cursor = 1;
	while (buffer[cursor] != '.') {
		zhengshu[cursor - 1] = buffer[cursor];
		cursor++;
	}
	zhengshu[cursor++ - 1] = '\0';
	int len1 = strlen(zhengshu);
	while (buffer[cursor] != 'E') {
		xiaoshu[cursor - len1 - 2] = buffer[cursor];//这里数组访问到了xiaoshu[-1]，可以操作但会报错，Stack around the variable 'xiaoshu' was corrupted
		cursor++;
	}
	xiaoshu[cursor++ - len1 - 2] = '\0';
	int len2 = strlen(xiaoshu);
	strcpy(buffer, buffer + cursor);//strncpy
	zhishu = atoi(buffer);

	//printf("%c%s.%sE%d\n", zhengfu, zhengshu, xiaoshu, zhishu);

	if (zhengfu == '-')
		printf("%c", zhengfu);

	if (zhishu > 0) {//手动复制字符串
		if (zhishu < len2) {
			int i = 0, j = 0;
			for (; i < zhishu; i++)
				zhengshu[len1 + i] = xiaoshu[i];
			zhengshu[len1 + i] = '\0';
			for (; j < len2 - i; j++)
				xiaoshu[j] = xiaoshu[j + i];
			xiaoshu[j] = '\0';
			printf("%s.%s", zhengshu, xiaoshu);
		}
		else {
			int i = 0;
			strcat(zhengshu, xiaoshu);
			for (; i < zhishu - len2; i++)
				buffer[i] = '0';
			buffer[i] = '\0';
			strcat(zhengshu, buffer);
			printf("%s", zhengshu);
		}
	}
	else if (zhishu < 0) {//用了字符串函数
		zhishu = zhishu * (-1);
		if (zhishu >= len1) {
			int i = 0;
			for (; i < zhishu - len1; i++)
				buffer[i] = '0';
			buffer[i] = '\0';
			strcat(zhengshu, xiaoshu);
			strcat(buffer, zhengshu);
			strcpy(xiaoshu, buffer);
			zhengshu[0] = '0';
			zhengshu[1] = '\0';
		}
		else {
			strcat(zhengshu, xiaoshu);
			strcpy(xiaoshu, zhengshu + len1 - zhishu);
			zhengshu[len1 - zhishu] = '\0';
		}

		printf("%s.%s", zhengshu, xiaoshu);
	}
	else {
		printf("%s.%s", zhengshu, xiaoshu);
	}

	system("pause");
	return 0;
}
//写得不够简洁，看这个https://www.liuchuo.net/archives/2061，用了string。
//或者看书上的也使用了char[]，都比我写得简单得多。