#pragma warning(disable: 4996)
#include <cstdio>
#include <algorithm>

using namespace std;

struct Product {
	double amount, price, unitPrice;
};

bool cmp(Product a, Product b) {
	return a.unitPrice > b.unitPrice;
}

int main(int argc, char *argv[]) {
	int N;
	double D;//ע������ҲӦ����double��
	scanf("%d %lf", &N, &D);
	Product *products = new Product[N];
	for (int i = 0; i < N; i++)
		scanf("%lf", &products[i].amount);
	for (int i = 0; i < N; i++) {
		scanf("%lf", &products[i].price);
		products[i].unitPrice = products[i].price / products[i].amount;
	}
	sort(products, products + N, cmp);
	double profit = 0;
	for (int i = 0; i < N; i++) {
		if (products[i].amount < D) {
			D -= products[i].amount;
			profit += products[i].price;
		}
		else {
			profit += D * products[i].unitPrice;
			break;
		}
	}
	printf("%.2f", profit);
	system("pause");
	return 0;
}
//д��̰�ķ����⣬���������ݹ飬̫���꣬��Ҫ����Ϊ�о������»���ȫû����