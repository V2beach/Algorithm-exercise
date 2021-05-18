#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	char days[7][5] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	int day, hour, minute, i = 0;
	char str1[61], str2[61], str3[61], str4[61];

	scanf("%s", str1);
	scanf("%s", str2);
	for (; i < 60; i++)
		if (str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G') {//只有7天
			day = str1[i] - 'A';
			break;
		}
	for (i++; i < 60; i++)//对，i++不用放在上面，放在这里就行，我跟书上思路基本一样
		if (str1[i] == str2[i]) {
			if (str1[i] >= '0' && str1[i] <= '9') {
				hour = str1[i] - '0';
				break;
			}
			else if (str1[i] >= 'A' && str1[i] <= 'N') {
				hour = str1[i] - 'A' + 10;
				break;
			}
		}
	scanf("%s", str3);
	scanf("%s", str4);
	for (i = 0; i < 60; i++)
		if (str3[i] >= 'a' && str3[i] <= 'z' || str3[i] >= 'A' && str3[i] <= 'Z') {
			if (str3[i] == str4[i]) {
				minute = i;
				break;
			}
		}
	printf("%s %02d:%02d", days[day], hour, minute);//直接用02格式化就可以控制有无0了

	system("pause");
	return 0;
}
//读题太重要了，最近这几个题完全就是阅读理解
//写完代码没切换项目，我犯傻了，找了十分钟bug