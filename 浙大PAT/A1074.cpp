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

//有没有可能写一个原地反转算法？
int main(int argc, char* argv[]) {
	//读数据->存成静态链表->遍历一遍并存入vector->按顺序反转链表->输出
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
	while (nodes[index].next != -1) {//A1052我用了do while的写法
		index = nodes[index].next;
		nodes_valid.push_back(nodes[index]);
	}

	N = nodes_valid.size();
	if (K > N) K = N;//测试点并没有这种情况
	int times = 0;//K == 0
	if (K != 0) times = N / K;//比如N6K2, times==3

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
//1和5检查点错了，一共7个检查点，得了19分。
//检查点1 5错因，完全读错题了，you are supposed to reverse the links of every K elements on L.
//every!!!every!!!every!!!怎么这么反人类啊，或者说我读英文题判断陷阱的能力怎么这么差啊。
//00100 6 2
//00000 4 99999
//00100 1 12309
//68237 6 -1
//33218 3 00000
//99999 5 68237
//12309 2 33218
//(123456, 214365)
//思维不熟练，绕了很多弯，写完第一遍就花了一个小时，
//AC俩小时，代码是完全重写的，重写这遍一次就AC只花了十几分钟，
//这样不行啊，PAT一共就给三个小时时间