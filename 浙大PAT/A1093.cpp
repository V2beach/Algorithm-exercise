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
//��ȷ��Ư����˼·�ǣ��ҵ�ÿһ��A��������ߺ��ұߵ�P��T�������˻���
//�����ļ����������ڱ���ʱ���ס��ĳ���������PT������������ȡ�ࡣ
//��������д��2 3 4�������Ե�ȫ��ʱ�ˣ�Ҫ�ǿ�������������������ķ�...
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