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
	//读初始值→将数据存为静态链表→根据静态链表得到两个字符串→从后往前对比字符串找到suffix
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
	vector<int> pos_1, pos_2;//地址没存下来，找到这个字母之外还需要找到这个字母的位置
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
		printf("%05d", index);//30分钟解决，还没debug，下去买个夜宵，2021-04-02，欧耶我又开始刷题了
	else 
		cout << index;
	system("pause");
	return 0;
}
//3次调通，但最后两个检查点错了，拿到了20分。
//想的时间要和写五五开，找测试点的努力有时大于写代码。
//检查点4——要注意输出的是地址！！！要用%05d补0；检查点5——巨大的坑...后缀相同的条件是，必须字母和“地址”都是一样的！！！！！我真是服了，https://blog.csdn.net/weixin_41359213/article/details/107477558