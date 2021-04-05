#pragma warning(disable: 4996)
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int nax = 26 * 26 * 26 * 10 + 1;
vector<int> result[nax];//���������������ȫ�ֱ����Ͳ��ᱬջ��...���Ҳ���ܷ���namespace���棬���һ�£�

int hashFunc(char name[5]) {
	//int hashValue = (name[0] - 'A' + 1) * (name[1] - 'A' + 1) * (name[2] - 'A' + 1) * (name[3] - '0' + 1);
	//����������д����������ﻹ�ǻ��أ����һ�������ϣ�㷨����ע
	int hashValue = 0;
	for (int i = 0; i < 3; i++)
		hashValue = 26 * hashValue + name[i] - 'A';
	hashValue = 10 * hashValue + name[3] - '0';
	return hashValue;
}

int main(int argc, char *argv[]) {
	int N, K;
	scanf("%d %d", &N, &K);
	int course, students;
	char name[5];
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &course, &students);
		for (int j = 0; j < students; j++) {
			scanf("%s", name);
			result[hashFunc(name)].push_back(course);
		}
	}
	int hash;
	for (int i = 0; i < N; i++) {
		scanf("%s", name);
		hash = hashFunc(name);
		sort(result[hash].begin(), result[hash].end());
		printf("%s ", name);
		printf("%d", result[hash].size());//result[hash].empty() ? printf("0") : ����Ҫ
		for (int j = 0; j < result[hash].size(); j++)
			printf(" %d", result[hash][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}
//˼·��ȷ��һ�ι����������ļ�������������S��ȫһ����hashFunc��һ����
//��Ȼ��Ҫ������ǰ/����ǰ���ڲݸ�ֽ�������˼·������Ҫ��Ҫ�������ϰ�ߣ�����
//1.�����ֻ���2.д����ǰ��������˼·�ݸ塣
//��ע�������Ҫ�úõ�����