#pragma warning(disable: 4996)
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {

	system("pause");
	return 0;
}
//按照书上的做法，考察每一位为一时，其他位为任意数，总共会出现多少次1，逐位考察。
//规律是，当第i位是1时，n~i+1位是原来的数字-1种可能，i-1~1位是10^(i-1)种可能，相乘即可
//也不对...
//算了，这个题留着有空的时候做着玩吧。