#include <cstdio>
int main(int argc, char *argv[]) {
	char base13[15] = "0123456789ABC";
	std::printf("#");
	for (int i = 0; i < 3; i++) {
		int decimal;
		std::scanf("%d", &decimal);
		std::printf("%c%c", base13[decimal / 13], base13[decimal % 13]);//因为只是两位数，可以选择不用通用的进制转换代码
	}
	return 0;
}
//int main(int argc, char *argv[]) {
//	int decimal, base = 13;//10->base
//	int result[10];
//	char base13[3] = { 'A', 'B', 'C' };
//	
//	printf("#");
//	for (int i = 0; i < 3; i++) {
//		int cursor = 0;
//		scanf("%d", &decimal);
//		do {
//			result[cursor++] = decimal % base;
//			decimal = decimal / base;
//		} while (decimal != 0);
//		if (cursor == 2) {
//			for (int j = cursor - 1; j >= 0; j--) {
//				if (result[j] < 10)
//					printf("%d", result[j]);
//				else
//					printf("%c", base13[result[j] - 10]);
//			}
//		}
//		else
//			if (result[0] < 10)
//				printf("0%d", result[0]);
//			else
//				printf("0%c", base13[result[0] - 10]);
//	}
//
//
//	system("pause");
//	return 0;
//}