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
		cin >> numbers[i];//如果用scanf/printf就不对了，原因尚不明确
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
//本来是想用computeWeight计算数字的权重，但不好定义，遂根据教材的做法选择S1 + S2 < S2 + S1则S1, S2的方法。
//我需要摈弃一种想法：一个思路必须要由我自己想出来才是真的会了，错误，学习别人的优秀思路，哪怕只是学到了方法都是对自己的提升，
//再不济总比你闷着头看两个小时，然后发现什么都没想出来白白浪费时间好啊？不会，就看别人的思路，不然学习的内容和时间比就会太低，
//学习效率太低。我到底在干什么？一切都没进入正轨。唯一稳定增加的只有体重，这样不行！这样下去不行！又开始陷入怪圈了！！！
//学得太慢导致焦虑，什么都想做，什么都做不专注，最后什么都没做好。脑子清醒一点，该干什么就干什么。