#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int *shuffle(int card[], int order[]) {//card��ϴ��ǰ������
	int *result = (int *)malloc(54 * sizeof(int));

	for (int i = 0; i < 54; i++)//ѭ��54��
		result[order[i]] = card[i];

	return result;
}

int main(int argc, char *argv[]) {
	int k;//k<=20
	scanf("%d", &k);

	int card[54];//ÿ�����ֶ�Ӧһ�Ź̶����ƣ�����card[3]��15����ô�������ƾ���Heart2
	int *result;
	for (int i = 0; i < 54; i++)//��Ŀ������Ͳ��ÿո���
		card[i] = i + 1;

	int order[54];//ϴ��˳��
	for (int i = 0; i < 54; i++) {
		scanf("%d", &order[i]);
		order[i]--;//��Ӧ����λ��
	}

	//ϴ��
	result = card;
	for (int i = 0; i < k; i++)
		result = shuffle(result, order);

	//����ʽ������
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