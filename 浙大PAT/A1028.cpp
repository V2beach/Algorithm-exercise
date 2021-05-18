#pragma warning(disable: 4996)
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Motherfucker {
	long id;
	char name[9];
	int grade;
};

bool cmp1(Motherfucker a, Motherfucker b) {
	return a.id < b.id;//id不可能相同
}

bool cmp2(Motherfucker a, Motherfucker b) {
	int c = strcmp(a.name, b.name);
	if (c != 0) return c < 0;
	else return a.id < b.id;
}

bool cmp3(Motherfucker a, Motherfucker b) {
	if (a.grade != b.grade) return a.grade < b.grade;
	else return a.id < b.id;
}

int main(int argc, char *argv[]) {
	long N;
	int C;
	scanf("%ld %d", &N, &C);
	Motherfucker *motherfuckers = new Motherfucker[N];
	for (int i = 0; i < N; i++)
		scanf("%ld %s %d", &motherfuckers[i].id, motherfuckers[i].name, &motherfuckers[i].grade);

	switch (C) {
	case 1:
		sort(motherfuckers, motherfuckers + N, cmp1);
		break;
	case 2:
		sort(motherfuckers, motherfuckers + N, cmp2);
		break;
	case 3:
		sort(motherfuckers, motherfuckers + N, cmp3);
		break;
	default:
		printf("Surprise Motherfucker!");
	}

	for (int i = 0; i < N; i++)
		printf("%06ld %s %d\n", motherfuckers[i].id, motherfuckers[i].name, motherfuckers[i].grade);

	system("pause");
	return 0;
}
//这题值25？