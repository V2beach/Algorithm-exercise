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

bool insertionSort(int* &array, int* sorted, int n) {//���Ŷ�д�������Ž��ˣ������ԵĶ���Ҫ���Σ���Ҫ����������ʼ�
	bool flag = false;
	for (int i = 1; i < n; i++) {//ȷʵ�ǴӺ���ǰö�ٱȽϺ�
		int temp = array[i], j = i;
		while (j > 0 && temp < array[j - 1]) {
			array[j--] = array[j - 1];
		}
		array[j] = temp;
		if (flag) return flag;
		if (areTheyTheSame(array, sorted, n)) flag = true;//����һ��
	}
	return flag;
}

void merge(int* &array, int l1, int l2, int r1, int r2, int n) {//Ҫдԭ���㷨...��Ҫ�ǲ���ֱ����sort�������дһ����
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
	for (int step = 2; step / 2 < n; step *= 2) {//step��һ�����ź��������Ԫ�أ�step / 2�������Ұ�ߣ�������ûѡ��<=����step / 2 < n���Լ���һ��4����/5���������Ӿ�֪���ˣ�������д��
		for (int i = 0; i < n; i += step) {//ÿ�������Ԫ��
			int mid = i + step / 2 - 1;//��������Ԫ�ظ�����step / 2��
			if (mid + 1 < n)//�ұ��������û��Ԫ���ˣ�����6��Ԫ�ص����У�ֻ�ܵ�һ��������飬�ڶ��η���ʱ�ڶ�����ұ�����Ϊ����
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
		printf(" %d", array[i]);//ע�⣬�ո����з�һ�����Ա�OJ����
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
//һ�ι��ˣ�ֻ�������д��̫�������ˣ�����ԭ����û��������⡣