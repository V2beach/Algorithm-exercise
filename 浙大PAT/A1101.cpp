#pragma warning(disable: 4996)
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	long long N;
	scanf("%lld", &N);
	long long *nums = new long long[N];
	long long nin = 1000000001, nax = -1;
	long long *nins = new long long[N];
	long long *naxs = new long long[N];
	//���õ����˼·�Ǽ�¼��ÿ��Ԫ����ߵ����ֵnax���ұߵ���Сֵnin����Ҫ�������顣
	for (long long i = 0; i < N; i++) {
		scanf("%lld", &nums[i]);
		naxs[i] = nax;
		if (nax < nums[i])
			nax = nums[i];
	}
	naxs[0] = -1;
	for (long long i = N - 1; i >= 0; i--) {
		nins[i] = nin;
		if (nin > nums[i])
			nin = nums[i];
	}
	nins[N - 1] = 1000000001;
	//������Щ������Ϊpivot
	long long count = 0;
	vector<long long> answer;
	for (long long i = 0; i < N; i++) {
		if (naxs[i] <= nums[i] && nins[i] >= nums[i]) {//ǧ��ע�ⲻҪ��nins��naxsŪ���ˣ����ֵ����ߵ�С������Сֵ����ߵĴ���
			answer.push_back(nums[i]);
			count++;
		}
	}
	sort(answer.begin(), answer.end());
	printf("%lld\n", count);
	//for (int i = 0; i < N; i++) {
	//	printf("%lld %lld\n", naxs[i], nins[i]);
	//}
	//system("pause");
	if (answer.empty()) { printf("\n"); return 0; }//һ��һ��ע������ĸ�ʽ����ʽ������ͣ����0��ʱ�������0\n\n��д����ע�
	printf("%lld", answer[0]);
	for (long long i = 1; i < answer.size(); i++) {
		printf(" %lld", answer[i]);
	}
	system("pause");
	return 0;
}
//һ�ι���������PATs�ǵ���ֱ�ۺܶ࣬�������뵽��
//һ��һ��ע������ĸ�ʽ����ʽ������ͣ����0��ʱ�������0\n\n��д����ע�