#pragma warning(disable: 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(char* a, char* b) {
	return strcmp(a, b) < 0;
}

int main(int argc, char *argv[]) {
	int N, K;
	scanf("%d %d", &N, &K);
	vector<char*> *result = new vector<char*>[K + 1];//Խ��ÿ�α���������һ������ξ�Ȼû������...
	int courses, no;
	for (int i = 0; i < N; i++) {
		char *name = new char[5];//���Ҫ�ŵ����棬�����Ƴ�ȥ�Ա�һ�����������⣬���vector����ǵ�ַ��ָ�룬�������������൱����ʼ����ֻ������һƬ�ռ䣬����������˵�name������һ���ġ�
		scanf("%s %d", name, &courses);
		for (int j = 0; j < courses; j++) {
			scanf("%d", &no);
			result[no].push_back(name);
		}
	}
	for (int i = 1; i <= K; i++) {
		printf("%d %d\n", i, result[i].size());
		sort(result[i].begin(), result[i].end(), cmp);
		for (int j = 0; j < result[i].size(); j++)
			printf("%s\n", result[i][j]);
	}
	system("pause");
	return 0;
}
//˼·���������S��ȫһ������Ȼ��������̫����...���Ƿ�����һЩ����ϵ����⣬��ע����д���ˡ�