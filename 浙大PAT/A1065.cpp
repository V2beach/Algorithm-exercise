#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);//溢出，两个正数或者两个负数
		long long sum = a + b;//注意这里，如果没有sum，直接用a + b的话测试点不通过，奇怪了
		if (a > 0 && b > 0 && sum < 0) {
			printf("Case #%d: true", i);
		}
		else if (a < 0 && b < 0 && sum >= 0) {//可能等于，要算一算溢出情况
			printf("Case #%d: false", i);
		}
		else {
			if (sum > c)
				printf("Case #%d: true", i);
			else
				printf("Case #%d: false", i);
		}
		if (i != T)
			printf("\n");
	}

	system("pause");
	return 0;
}