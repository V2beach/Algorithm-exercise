#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);
	char **niHonJin = new char*[N];//�ձ��˺����ﶼ��NiHonJin
	int *len = new int[N];
	getchar();//�ܹ֣���Ϊû����gets����gets_s����ʱ�����һ���ַ�
	for (int i = 0; i < N; i++) {
		niHonJin[i] = new char[256];
		//gets_s(niHonJin[i], 300);//PAT�ı�������֧�������������
		//scanf("%[^\n]", niHonJin[i]);
		int j = 0;
		while (((niHonJin[i][j] = getchar()) != '\n'))//���ˣ���ԭʼ�Ķ�����д��
			j++;
		if (j == 0) {//���ֿ��ַ���������ʵ���Ե�û��������������һ�����Ե㵽����ɶ��
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
		if (suff != -1)//����ж�����Ҫ�����棬��Ϊ����maxLen�ڵ����һλ(Ҳ����str[0])�ǲ�һ����
			break;
		if (i == maxLen) {//���һ�����Ե��������������2 123456 123465
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
//����˼·�Ƿ�ת�ַ�������Ҳдһ�����Կ�