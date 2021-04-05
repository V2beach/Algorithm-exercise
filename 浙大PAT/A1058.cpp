#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {//分别是17进制和29进制
	int galleon[2], sickle[2], knut[2], gal, sic, knu;
	scanf("%d.%d.%d %d.%d.%d", &galleon[0], &sickle[0], &knut[0], &galleon[1], &sickle[1], &knut[1]);

	gal = galleon[0] + galleon[1];
	sic = sickle[0] + sickle[1];
	knu = knut[0] + knut[1];

	sic = sic + knu / 29;
	knu = knu % 29;
	gal = gal + sic / 17;
	sic = sic % 17;

	printf("%d.%d.%d", gal, sic, knu);

	system("pause");
	return 0;
}
//不是这也太简单了