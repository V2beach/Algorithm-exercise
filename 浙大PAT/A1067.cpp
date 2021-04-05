#pragma warning(disable: 4996)
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {//略绕
	long N = 0, count = 0;
	scanf("%ld", &N);
	long *numbers = new long[N];
	long *cursor = new long[N];
	for (int i = 0; i < N; i++) {
		scanf("%ld", &numbers[i]);//读到第i个位置放着number
		cursor[numbers[i]] = i;//数字number在cursor这个位置
	}
	int index = 1;
	while (numbers[0] != 0 || (numbers[0] == 0 && count == 0)) {
		if (cursor[0] == numbers[0]) {//要判断是否是最后一次交换
			bool isValid = true;
			for (; index < N; index++) {//换一个其他的不在自己该在位置的数
				if (index != numbers[index] && numbers[index] != 0) {
					long temp1 = cursor[0], temp2 = cursor[numbers[index]];
					swap(cursor[0], cursor[numbers[index]]);//cursor[numbers[i]]即i
					swap(numbers[temp1], numbers[temp2]);
					isValid = false;
					break;
				}
			}
			if (isValid && numbers[0] == 0) break;
			if (isValid) swap(numbers[cursor[0]], numbers[cursor[cursor[0]]]);//成功了，cursor[cursor[0]]应该是0
		}
		else {
			long temp1 = cursor[0], temp2 = cursor[cursor[0]];
			swap(cursor[0], cursor[cursor[0]]);//将0和0所在下标的那个数交换
			swap(numbers[temp1], numbers[temp2]);
		}
		count++;
	}
	printf("%ld", count);
	system("pause");
	return 0;
}
//这题就是大体知道测试点是什么，半卡测试点过的，
//又拖了一下午，状态差到离谱，我到底在干什么？？？
//我不能受别人节奏的影响，应该让研友成为一个积极的因素。
//要想办法回到考编译前的那个状态。