#pragma warning(disable: 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	char str[100001];
	scanf("%s", str);
	long len = strlen(str);
	long count = 0;
	long *countPs = new long[len], countP = 0;
	long *countTs = new long[len], countT = 0;
	long *whereisa = new long[len], countA = 0;
	for (long i = 0; i < len; i++) {
		if (str[i] == 'P') countP++;
		else if (str[i] == 'A') {
			whereisa[countA++] = i;
			countPs[i] = countP;
			countTs[i] = countT;
		}
		else countT++;
	}
	for (long i = 0; i < countA; i++) {
		count += countPs[whereisa[i]] * (countT - countTs[whereisa[i]]);
	}
	count = count % 1000000007;
	printf("%ld", count);
	system("pause");
	return 0;
}
//正确且漂亮的思路是，找到每一个A，计算左边和右边的P和T的总数乘积，
//而最快的计数方法是在遍历时候记住到某个点的所有PT数量，别忘记取余。
//下面这种写法2 3 4三个测试点全超时了，要是考试碰上这样的题是真的烦...
//#pragma warning(disable: 4996)
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int main(int argc, char *argv[]) {
//	char str[100001];
//	scanf("%s", str);
//	int len = strlen(str), count = 0;
//	for (int i = 0; i < len; i++) {//P
//		if (str[i] == 'P')
//			for (int j = i + 1; j < len; j++)
//				if (str[j] == 'A')
//					for (int k = j + 1; k < len; k++)
//						if (str[k] == 'T')
//							count++;
//	}
//	printf("%d", count);
//	system("pause");
//	return 0;
//}