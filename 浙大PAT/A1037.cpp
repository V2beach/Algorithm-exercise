#pragma warning(disable: 4996)
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool nonDecreasing(long a, long b) {
	return a < b;
}

bool nonIncreasing(long a, long b) {
	return a > b;
}

int main(int argc, char *argv[]) {
	long getBack;
	long Nc;
	scanf("%ld", &Nc);
	vector<long> couponsPositive;
	vector<long> couponsNegative;
	for (int i = 0; i < Nc; i++) {
		scanf("%ld", &getBack);
		if (getBack > 0)  couponsPositive.push_back(getBack);
		else if (getBack < 0)  couponsNegative.push_back(getBack);
		else;
	}
	sort(couponsPositive.begin(), couponsPositive.end(), nonIncreasing);
	sort(couponsNegative.begin(), couponsNegative.end(), nonDecreasing);
	long Np;
	scanf("%ld", &Np);
	vector<long> productPositive;
	vector<long> productNegative;
	for (int i = 0; i < Np; i++) {
		scanf("%ld", &getBack);
		if (getBack > 0)  productPositive.push_back(getBack);
		else if (getBack < 0)  productNegative.push_back(getBack);
		else;
	}
	sort(productPositive.begin(), productPositive.end(), nonIncreasing);
	sort(productNegative.begin(), productNegative.end(), nonDecreasing);
	getBack = 0;
	if (!couponsNegative.empty() && !productNegative.empty())
		for (int i = 0; i < couponsNegative.size() && i < productNegative.size(); i++)
			getBack += couponsNegative[i] * productNegative[i];
	else;
	if (!couponsPositive.empty() && !productPositive.empty())
		for (int i = 0; i < couponsPositive.size() && i < productPositive.size(); i++)
			getBack += couponsPositive[i] * productPositive[i];
	else;
	printf("%ld", getBack);
	system("pause");
	return 0;
}
//教训：还是那句话，别想着找最优解，先把问题解出来再想优化。
//想把数据拆成两部分就拆，只是O(n)的复杂度，为什么不做？
//十分钟就写完的题，非要搞两个小时，自己纠结纠结到最后还是这么做了，实在是太菜了。