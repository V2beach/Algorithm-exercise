#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
	int add;
	long key;
	int next;
}nodes[100001];

bool cmp(Node a, Node b) {
	return a.key < b.key;
}

//д�꽱���Լ�ˮȺ
int main(int argc, char* argv[]) {
	//��ȡ����->!!��ɾ�̬������˳�����ų����������ڵ���Ч��!!->����key����->����˳���޸�next->���->����->�ұ߽�ֵ�ȵ�ͨ���Ե�->ѧϰ���˵Ĵ�
	int N, add_0;
	cin >> N >> add_0;
	if (add_0 == -1) {
		printf("0 -1");
		return 0;
	}

	int add, next;
	long key;
	for (int i = 0; i < N; i++) {
		cin >> add >> key >> next;
		nodes[add].add = add;
		nodes[add].key = key;
		nodes[add].next = next;
	}

	vector<Node> nodes_valid;
	int index = add_0;
	do {
		//��Node *node = new Node;�������ĸ����ã�
		nodes_valid.push_back(nodes[index]);
		index = nodes[index].next;
	} while (index != -1);

	N = nodes_valid.size();
	sort(nodes_valid.begin(), nodes_valid.end(), cmp);
	add_0 = nodes_valid[0].add;
	nodes_valid[N - 1].next = -1;
	for (int i = 0; i < N - 1; i++)
		nodes_valid[i].next = nodes_valid[i + 1].add;

	printf("%d %05d\n", N, add_0);
	for (int i = 0; i < N - 1; i++)
		printf("%05d %ld %05d\n", nodes_valid[i].add, nodes_valid[i].key, nodes_valid[i].next);
	printf("%05d %ld %d", nodes_valid[N - 1].add, nodes_valid[N - 1].key, nodes_valid[N - 1].next);

	system("pause");
	return 0;
}
//���Ե�4Ӧ�ú������뵽�������ȫ��xx��ô�죿���������ȫ����Ч������ô�죿����ĥ����1����Сʱ��
//20���ӣ���һ���ύ21�֣�1��4����ûͨ�����²��Ǳ߽�ֵ��
//�������壬���Ե�������Ч���ݣ�д���ٸľ��е������ˣ���Ϊû��ɾ�̬����ֻ����дһ�顣
//int N, add_0;
//cin >> N >> add_0;
//
//Node* nodes = new Node[N]; //new�Ƿ���һ����ַ��������
//for (int i = 0; i < N; i++)
//	cin >> nodes[i].add >> nodes[i].key >> nodes[i].next;
//
//sort(nodes, nodes + N, cmp);
//add_0 = nodes[0].add;
//nodes[N - 1].next = -1;
//for (int i = 0; i < N - 1; i++)
//	nodes[i].next = nodes[i + 1].add;
//
//printf("%d %05d\n", N, add_0);
//for (int i = 0; i < N - 1; i++)
//	printf("%05d %ld %05d\n", nodes[i].add, nodes[i].key, nodes[i].next);
//printf("%05d %ld %d", nodes[N - 1].add, nodes[N - 1].key, nodes[N - 1].next);