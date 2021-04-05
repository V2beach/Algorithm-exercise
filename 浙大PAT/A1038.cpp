#pragma warning(disable: 4996)
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
	return a + b < b + a;
}

int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);
	string *numbers = new string[N];
	ios::sync_with_stdio(false);
	for (int i = 0; i < N; i++)
		cin >> numbers[i];//�����scanf/printf�Ͳ����ˣ�ԭ���в���ȷ
	sort(numbers, numbers + N, cmp);
	string answer;
	for (int i = 0; i < N; i++)
		answer += numbers[i];
	while (answer[0] == '0' && answer.size() != 0)
		answer.erase(answer.begin());
	if (answer.size() == 0) printf("0");
	else cout << answer;
	system("pause");
	return 0;
}
//����������computeWeight�������ֵ�Ȩ�أ������ö��壬����ݽ̲ĵ�����ѡ��S1 + S2 < S2 + S1��S1, S2�ķ�����
//����Ҫ����һ���뷨��һ��˼·����Ҫ�����Լ������������Ļ��ˣ�����ѧϰ���˵�����˼·������ֻ��ѧ���˷������Ƕ��Լ���������
//�ٲ����ܱ�������ͷ������Сʱ��Ȼ����ʲô��û������װ��˷�ʱ��ð������ᣬ�Ϳ����˵�˼·����Ȼѧϰ�����ݺ�ʱ��Ⱦͻ�̫�ͣ�
//ѧϰЧ��̫�͡��ҵ����ڸ�ʲô��һ�ж�û�������졣Ψһ�ȶ����ӵ�ֻ�����أ��������У�������ȥ���У��ֿ�ʼ�����Ȧ�ˣ�����
//ѧ��̫�����½��ǣ�ʲô��������ʲô������רע�����ʲô��û���á���������һ�㣬�ø�ʲô�͸�ʲô��