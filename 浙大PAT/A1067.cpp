#pragma warning(disable: 4996)
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {//����
	long N = 0, count = 0;
	scanf("%ld", &N);
	long *numbers = new long[N];
	long *cursor = new long[N];
	for (int i = 0; i < N; i++) {
		scanf("%ld", &numbers[i]);//������i��λ�÷���number
		cursor[numbers[i]] = i;//����number��cursor���λ��
	}
	int index = 1;
	while (numbers[0] != 0 || (numbers[0] == 0 && count == 0)) {
		if (cursor[0] == numbers[0]) {//Ҫ�ж��Ƿ������һ�ν���
			bool isValid = true;
			for (; index < N; index++) {//��һ�������Ĳ����Լ�����λ�õ���
				if (index != numbers[index] && numbers[index] != 0) {
					long temp1 = cursor[0], temp2 = cursor[numbers[index]];
					swap(cursor[0], cursor[numbers[index]]);//cursor[numbers[i]]��i
					swap(numbers[temp1], numbers[temp2]);
					isValid = false;
					break;
				}
			}
			if (isValid && numbers[0] == 0) break;
			if (isValid) swap(numbers[cursor[0]], numbers[cursor[cursor[0]]]);//�ɹ��ˣ�cursor[cursor[0]]Ӧ����0
		}
		else {
			long temp1 = cursor[0], temp2 = cursor[cursor[0]];
			swap(cursor[0], cursor[cursor[0]]);//��0��0�����±���Ǹ�������
			swap(numbers[temp1], numbers[temp2]);
		}
		count++;
	}
	printf("%ld", count);
	system("pause");
	return 0;
}
//������Ǵ���֪�����Ե���ʲô���뿨���Ե���ģ�
//������һ���磬״̬����ף��ҵ����ڸ�ʲô������
//�Ҳ����ܱ��˽����Ӱ�죬Ӧ�������ѳ�Ϊһ�����������ء�
//Ҫ��취�ص�������ǰ���Ǹ�״̬��