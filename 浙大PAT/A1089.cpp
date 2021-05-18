#pragma warning(disable: 4996)
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool areTheyTheSame(int a[], int b[], int n) {
	for (int i = 0; i < n; i++)
		if (a[i] != b[i])
			return false;
	return true;
}

bool insertionSort(int* &array, int* sorted, int n) {//插排都写不出最优解了，基础性的东西要记牢，主要内容整理个笔记
	bool flag = false;
	for (int i = 1; i < n; i++) {//确实是从后往前枚举比较好
		int temp = array[i], j = i;
		while (j > 0 && temp < array[j - 1]) {
			array[j--] = array[j - 1];
		}
		array[j] = temp;
		if (flag) return flag;
		if (areTheyTheSame(array, sorted, n)) flag = true;//再跑一轮
	}
	return flag;
}

void merge(int* &array, int l1, int l2, int r1, int r2, int n) {//要写原地算法...主要是不想直接用sort，就随便写一个吧
	int *yarra = new int[n], i = l1, j = r1, index = l1;
	while (i <= l2 && j <= r2) {
		if (array[i] < array[j]) yarra[index++] = array[i++];
		else if (array[j] <= array[i]) yarra[index++] = array[j++];
	}
	while (i <= l2) yarra[index++] = array[i++];
	while (j <= r2) yarra[index++] = array[j++];
	for (int k = l1; k <= r2; k++)
		array[k] = yarra[k];
}

bool mergeSort(int* &array, int* sorted, int n) {
	bool flag = false;
	for (int step = 2; step / 2 < n; step *= 2) {//step是一组中排好序的所有元素，step / 2是左半或右半边，这里我没选择<=而是step / 2 < n，自己举一个4个数/5个数的例子就知道了，在书上写了
		for (int i = 0; i < n; i += step) {//每次排序的元素
			int mid = i + step / 2 - 1;//左边区间的元素个数有step / 2个
			if (mid + 1 < n)//右边区间可能没有元素了，比如6个元素的序列，只能第一分组分三组，第二次分组时第二组的右边区间为空了
				merge(array, i, mid, mid + 1, min(i + step - 1, n - 1), n);
		}
		if (flag) return flag;
		if (areTheyTheSame(array, sorted, n)) flag = true;
	}
	return flag;
}

void print(int* array, int n, int type) {
	if (type == 1) printf("Insertion Sort\n");
	if (type == 2) printf("Merge Sort\n");
	printf("%d", array[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", array[i]);//注意，空格不像换行符一样可以被OJ容忍
}

int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);
	int *origin1 = new int[N];
	int *origin2 = new int[N];
	int *sorted = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &origin1[i]);
		origin2[i] = origin1[i];
	}
	for (int i = 0; i < N; i++)
		scanf("%d", &sorted[i]);
	if (insertionSort(origin1, sorted, N)) print(origin1, N, 1);
	if (mergeSort(origin2, sorted, N)) print(origin2, N, 2);
	system("pause");
	return 0;
}
//一次过了，只是排序的写法太不熟练了，究其原因是没有真正理解。