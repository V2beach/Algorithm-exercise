#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);//�������������������������
		long long sum = a + b;//ע��������û��sum��ֱ����a + b�Ļ����Ե㲻ͨ���������
		if (a > 0 && b > 0 && sum < 0) {
			printf("Case #%d: true", i);
		}
		else if (a < 0 && b < 0 && sum >= 0) {//���ܵ��ڣ�Ҫ��һ��������
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