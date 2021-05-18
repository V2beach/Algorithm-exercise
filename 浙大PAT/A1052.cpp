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

//写完奖励自己水群
int main(int argc, char* argv[]) {
	//读取数据->!!存成静态链表并按顺序检查排除不在链表内的无效点!!->根据key排序->根据顺序修改next->输出->测试->找边界值等调通测试点->学习别人的答案
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
		//和Node *node = new Node;的区别？哪个更好？
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
//测试点4应该很容易想到——如果全是xx怎么办？这里是如果全是无效数据怎么办？最终磨蹭了1个半小时。
//20分钟，第一次提交21分，1和4检查点没通过（猜测是边界值。
//又是陷阱，测试点里有无效数据，写完再改就有点尴尬了，因为没存成静态链表，只好重写一遍。
//int N, add_0;
//cin >> N >> add_0;
//
//Node* nodes = new Node[N]; //new是返回一个地址，都忘了
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