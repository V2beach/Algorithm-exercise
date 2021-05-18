#pragma warning(disable: 4996)
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);
	int current = 0, seconds = 0, request;
	for (int i = 0; i < N; i++) {
		scanf("%d", &request);
		if (current == request)
			seconds += 5;
		else if (current < request) {
			seconds = seconds + (request - current) * 6 + 5;
			current = request;
		}
		else {
			seconds = seconds + (current - request) * 4 + 5;
			current = request;
		}
	}
	printf("%d", seconds);
	system("pause");
	return 0;
}
//我要被自己笑死了，盯着题看了半天，以为是求最优解