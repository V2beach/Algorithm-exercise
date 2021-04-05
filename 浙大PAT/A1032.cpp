#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	char word;
	int next;
}node[100001];

int main(int argc, char* argv[]) {
	//����ʼֵ�������ݴ�Ϊ��̬��������ݾ�̬����õ������ַ������Ӻ���ǰ�Ա��ַ����ҵ�suffix
	int add_1, add_2, N;
	cin >> add_1 >> add_2 >> N;

	int pos, next;
	char word;
	for (int i = 0; i < N; i++) {
		cin >> pos >> word >> next;
		node[pos].word = word;
		node[pos].next = next;
	}

	vector<char> words_1, words_2;
	vector<int> pos_1, pos_2;//��ַû���������ҵ������ĸ֮�⻹��Ҫ�ҵ������ĸ��λ��
	while (add_1 != -1) {
		words_1.push_back(node[add_1].word);
		pos_1.push_back(add_1);
		add_1 = node[add_1].next;
	}
	while (add_2 != -1) {
		words_2.push_back(node[add_2].word);
		pos_2.push_back(add_2);
		add_2 = node[add_2].next;
	}

	int index = -1;
	for (int i = 1; i <= min(words_1.size(), words_2.size()); i++) {
		if (words_1[words_1.size() - i] == words_2[words_2.size() - i] && pos_1[pos_1.size() - i] == pos_2[pos_2.size() - i])
			index = pos_1[words_1.size() - i];
		else break;
	}

	if (index != -1)
		printf("%05d", index);//30���ӽ������ûdebug����ȥ���ҹ����2021-04-02��ŷҮ���ֿ�ʼˢ����
	else 
		cout << index;
	system("pause");
	return 0;
}
//3�ε�ͨ�����������������ˣ��õ���20�֡�
//���ʱ��Ҫ��д���忪���Ҳ��Ե��Ŭ����ʱ����д���롣
//����4����Ҫע��������ǵ�ַ������Ҫ��%05d��0������5�����޴�Ŀ�...��׺��ͬ�������ǣ�������ĸ�͡���ַ������һ���ģ��������������Ƿ��ˣ�https://blog.csdn.net/weixin_41359213/article/details/107477558