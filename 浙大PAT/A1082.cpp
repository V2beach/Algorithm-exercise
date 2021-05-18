#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	char num[11], buffer[5];
	scanf("%s", num);
	int len = strlen(num), i = 0, digit1, digit2;
	if (num[0] == '-') {
		printf("Fu ");
		i = 1;
	}
	char str1[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
	char str2[5][5] = { "Shi", "Bai", "Qian", "Wan", "Yi" };
	vector<char*> result;//这里不能char[5]，要写char*，另外char*是类型，声明变量的时候要写char *val

	if (len == 1) {//个位数直接进下面的代码容易出错，干脆单独拿出来了
		printf("%s", str1[num[0] - '0']);
		system("pause");
		return 0;
	}
	else if (len == 2 && i == 1) {
		printf(" %s", str1[num[0] - '0']);
		system("pause");
		return 0;
	}
	else;


	for (; i < len; i++) {//最后再考虑空格，逐情况考虑
		if (num[i] == '0')
			if (i + 1 < len && num[i + 1] != '0')//零有很多种情况，这句是最关键的
				result.push_back(str1[num[i] - '0']);//其实就是把printf全都改成了vector.push_back
			else;
		else
			result.push_back(str1[num[i] - '0']);

		digit1 = (len - i) % 4;
		digit2 = (len - i) / 4;
		//当然可以把以下判断单位的情况整合到一两个公式里面，但没必要
		if (digit1 == 1) {//也就是到个位了
			if (digit2 == 0);
			else if (digit2 == 1) {
				if (i > 3 && i < len - 3) {//万和亿中可能只说一个，需要判断一下
					strncpy(buffer, num + i - 3, 4);
					if (atoi(buffer) == 0)
						continue;
				}
				result.push_back(str2[3]);//Wan
			}
			else if (digit2 == 2)
				result.push_back(str2[4]);//Yi
		}
		else if (digit1 == 2 && num[i] != '0')
			result.push_back(str2[0]);//Shi
		else if (digit1 == 3 && num[i] != '0')
			result.push_back(str2[1]);//Bai
		else if (digit1 == 0 && num[i] != '0')
			result.push_back(str2[2]);//Qian
	}

	printf("%s", result[0]);
	for (int k = 1; k < result.size(); k++)
		printf(" %s", result[k]);

	system("pause");
	return 0;
}
//刚开始就想着这个题如果改成用容器写可能会好一点，后来发现空格不好判断，还是得用容器
//写这个代码在第四个测试点第一次见段错误，说是越界或递归过深导致栈溢出之类的
//这种情况下，高中的做题思维就很好用了，首先考虑特殊点，比如0或者上下限~这里果然是0/个位数
//备注写一下，这个题没有看书上的做法，没带书