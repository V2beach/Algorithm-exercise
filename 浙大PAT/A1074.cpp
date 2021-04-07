#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int add;
	long data;
	int next;
}nodes[100001];

void print_format(int next) {
	if (next != -1) printf("%05d\n", next);
	else printf("%d\n", next);
}

void reverse_util(vector<Node>& nodes, int start, int end) {//[]
	for (int i = 0; i < end - start; i++)
		for (int j = start; j < end - i; j++)
			swap(nodes[j], nodes[j + 1]);
}

//��û�п���дһ��ԭ�ط�ת�㷨��
int main(int argc, char* argv[]) {
	//������->��ɾ�̬����->����һ�鲢����vector->��˳��ת����->���
	int add_0, N, K;
	cin >> add_0 >> N >> K;

	int add, data, next;
	for (int i = 0; i < N; i++) {
		cin >> add >> data >> next;
		nodes[add].add = add;
		nodes[add].data = data;
		nodes[add].next = next;
	}

	vector<Node> nodes_valid;
	int index = add_0;
	nodes_valid.push_back(nodes[index]);
	while (nodes[index].next != -1) {//A1052������do while��д��
		index = nodes[index].next;
		nodes_valid.push_back(nodes[index]);
	}

	N = nodes_valid.size();
	if (K > N) K = N;//���Ե㲢û���������
	int times = 0;//K == 0
	if (K != 0) times = N / K;//����N6K2, times==3

	for (int t = 1; t <= times; t++) {
		reverse_util(nodes_valid, (t - 1) * K, t * K - 1);
	}

	for (int i = 0; i < N - 1; i++) {
		printf("%05d %ld ", nodes_valid[i].add, nodes_valid[i].data);
		print_format(nodes_valid[i + 1].add);
	}
	printf("%05d %ld -1", nodes_valid[N - 1].add, nodes_valid[N - 1].data);

	system("pause");
	return 0;
}
//1��5������ˣ�һ��7�����㣬����19�֡�
//����1 5������ȫ�������ˣ�you are supposed to reverse the links of every K elements on L.
//every!!!every!!!every!!!��ô��ô�����డ������˵�Ҷ�Ӣ�����ж������������ô��ô���
//00100 6 2
//00000 4 99999
//00100 1 12309
//68237 6 -1
//33218 3 00000
//99999 5 68237
//12309 2 33218
//(123456, 214365)
//˼ά�����������˺ܶ��䣬д���һ��ͻ���һ��Сʱ��
//AC��Сʱ����������ȫ��д�ģ���д���һ�ξ�ACֻ����ʮ�����ӣ�
//�������а���PATһ���͸�����Сʱʱ��