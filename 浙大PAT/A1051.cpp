#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int M, N, K;

bool isPossible(vector<int> seq) {//思考量远大于代码量的一道题，核心思想是模拟题目过程！而不是从结果入手分析情况。
	int index = 1;
	stack<int> sequence;
	for (int i = 0; i < N; i++) {
		if (sequence.empty() || sequence.top() < seq[i]) {
			//if (index >= seq[])  考虑太多了，先提交一次试试看
			for (int j = index; j <= seq[i]; j++)
				sequence.push(j);
			if (sequence.size() > M) return false;
			index = seq[i] + 1;
			sequence.pop();
		}
		else {
			if (sequence.top() == seq[i])
				sequence.pop();
			else return false;
		}
	}
	return true;
}

int main(int argc, char* argv[]) {
	scanf("%d %d %d", &M, &N, &K);
	for (int i = 0; i < K; i++) {
		vector<int> seq;
		for (int j = 0; j < N; j++) {
			int temp;
			scanf("%d", &temp);
			seq.push_back(temp);
		}
		if (isPossible(seq)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	system("pause");
	return 0;
}