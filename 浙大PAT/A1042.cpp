#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int *shuffle(int card[], int order[]) {//card是洗牌前的牌序
	int *result = (int *)malloc(54 * sizeof(int));

	for (int i = 0; i < 54; i++)//循环54次
		result[order[i]] = card[i];

	return result;
}

int main(int argc, char *argv[]) {
	int k;//k<=20
	scanf("%d", &k);

	int card[54];//每个数字对应一张固定的牌，比如card[3]是15，那么第三张牌就是Heart2
	int *result;
	for (int i = 0; i < 54; i++)//单目运算符就不用空格了
		card[i] = i + 1;

	int order[54];//洗牌顺序
	for (int i = 0; i < 54; i++) {
		scanf("%d", &order[i]);
		order[i]--;//对应数组位置
	}

	//洗牌
	result = card;
	for (int i = 0; i < k; i++)
		result = shuffle(result, order);

	//按格式输出结果
	char map[5] = { 'S', 'H', 'C', 'D', 'J' };
	int j = 0;
	for (int i = 0; i < 54; i++) {
		j = fmod(result[i], 13);
		if (j != 0)
			printf("%c%d", map[result[i] / 13], j);
		else
			printf("%c13", map[result[i] / 13 - 1]);
		if (i != 53)
			printf(" ");
	}

	system("pause");
	return 0;
}