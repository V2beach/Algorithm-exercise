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
	vector<char*> result;//���ﲻ��char[5]��Ҫдchar*������char*�����ͣ�����������ʱ��Ҫдchar *val

	if (len == 1) {//��λ��ֱ�ӽ�����Ĵ������׳����ɴ൥���ó�����
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


	for (; i < len; i++) {//����ٿ��ǿո����������
		if (num[i] == '0')
			if (i + 1 < len && num[i + 1] != '0')//���кܶ���������������ؼ���
				result.push_back(str1[num[i] - '0']);//��ʵ���ǰ�printfȫ���ĳ���vector.push_back
			else;
		else
			result.push_back(str1[num[i] - '0']);

		digit1 = (len - i) % 4;
		digit2 = (len - i) / 4;
		//��Ȼ���԰������жϵ�λ��������ϵ�һ������ʽ���棬��û��Ҫ
		if (digit1 == 1) {//Ҳ���ǵ���λ��
			if (digit2 == 0);
			else if (digit2 == 1) {
				if (i > 3 && i < len - 3) {//������п���ֻ˵һ������Ҫ�ж�һ��
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
//�տ�ʼ���������������ĳ�������д���ܻ��һ�㣬�������ֿո񲻺��жϣ����ǵ�������
//д��������ڵ��ĸ����Ե��һ�μ��δ���˵��Խ���ݹ�����ջ���֮���
//��������£����е�����˼ά�ͺܺ����ˣ����ȿ�������㣬����0����������~�����Ȼ��0/��λ��
//��עдһ�£������û�п����ϵ�������û����