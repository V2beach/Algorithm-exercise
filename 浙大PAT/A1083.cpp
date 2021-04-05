#pragma warning(disable: 4996)
#include <cstdio>
#include <algorithm>

using namespace std;

struct Student {
	char name[11], id[11];
	int grade;
};

bool cmp(Student a, Student b) {
	return a.grade > b.grade;
}

int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);
	Student *students = new Student[N];
	for (int i = 0; i < N; i++)
		scanf("%s %s %d", students[i].name, students[i].id, &students[i].grade);
	sort(students, students + N, cmp);
	int grade1, grade2, count=0;
	scanf("%d %d", &grade1, &grade2);
	for (int i = 0; i < N; i++) {
		if (students[i].grade >= grade1 && students[i].grade <= grade2) {
			count++;
			printf("%s %s\n", students[i].name, students[i].id);
		}
	}
	if (count == 0)
		printf("NONE");
	system("pause");
	return 0;
}
//Îå·ÖÖÓ£¿