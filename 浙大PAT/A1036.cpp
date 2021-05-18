#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Student {
	char name[11];
	char gender;
	char id[11];
	int grade;
};

int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);
	Student *students = new Student[N];

	int maxno = -1, minno = -1, maxgrade = -100, mingrade = 101;
	for (int i = 0; i < N; i++) {
		scanf("%s %c %s %d", &students[i].name, &students[i].gender, &students[i].id, &students[i].grade);
		if (students[i].gender == 'M') {
			if (mingrade > students[i].grade) {
				minno = i;
				mingrade = students[i].grade;
			}
		}
		else {
			if (maxgrade < students[i].grade) {
				maxno = i;
				maxgrade = students[i].grade;
			}
		}
	}

	if (maxno == -1 || minno == -1) {
		if (maxno == -1) {
			printf("Absent\n");
			printf("%s %s\n", students[minno].name, students[minno].id);
			printf("NA");
		}
		else if (minno == -1) {
			printf("%s %s\n", students[maxno].name, students[maxno].id);
			printf("Absent\n");
			printf("NA");
		}
		else {
			printf("Absent\n");
			printf("Absent\n");
			printf("NA");
		}
	}
	else {
		printf("%s %s\n", students[maxno].name, students[maxno].id);
		printf("%s %s\n", students[minno].name, students[minno].id);
		printf("%d", students[maxno].grade - students[minno].grade);
	}

	system("pause");
	return 0;
}
//过于简单，所以怎么省事怎么写了（指写完一段然后复制粘贴）。