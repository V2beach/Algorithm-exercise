#pragma warning(disable: 4996)
#include <cstdio>
#include <algorithm>
//#include <cmath>

using namespace std;

struct Student {
	long id;
	int cLanguage;
	int math;
	int english;
	//double average;
	int average;
	long rank;//六位数的id，一共容许999999个rank
	int type;//priority, average:3, cLanguage:2, math:1, english:0
	bool operator == (const int &operand) {//这种做法要熟悉！
		return this->id == operand;
	}
};

bool cmpC(Student a, Student b) {//写法上，如果将科目整合到数组里可以简化这部分代码，但我没有那么做，另一种做法参见柳婼博客
	return a.cLanguage > b.cLanguage;
}

bool cmpM(Student a, Student b) {
	return a.math > b.math;
}

bool cmpE(Student a, Student b) {
	return a.english > b.english;
}

bool cmpA(Student a, Student b) {
	return a.average > b.average;
}

int main(int argc, char *argv[]) {
	int N, M;
	scanf("%ld %d", &N, &M);
	Student *students = new Student[N];
	for (int i = 0; i < N; i++) {
		scanf("%ld %d %d %d", &students[i].id, &students[i].cLanguage, &students[i].math, &students[i].english);
		//students[i].average = round((students[i].cLanguage + students[i].math + students[i].english) / 3.0);
		students[i].average = students[i].cLanguage + students[i].math + students[i].english;
		students[i].rank = 2020;
		students[i].type = 3;
	}

	char priority[] = {'E', 'M', 'C', 'A' };
	//按priority顺序排四次
	sort(students, students + N, cmpA);//平均分
	students[0].rank = 1;
	for (int i = 1; i < N; i++)
		students[i].rank = students[i].average == students[i - 1].average ? students[i - 1].rank : i + 1;
	
	//从这里往后三段可以整合成函数，但是没必要
	sort(students, students + N, cmpC);//C语言
	if (students[0].rank > 1) {
		students[0].rank = 1;
		students[0].type = 2;
	}
	for (int i = 1; i < N; i++) {//可以简化一下写法？好像没法用三目代替
		if (students[i].cLanguage == students[i - 1].cLanguage)
			if (students[i].rank > students[i - 1].rank) {
				students[i].rank = students[i - 1].rank;
				students[i].type = 2;
			}
			else;
		else
			if (students[i].rank > i + 1) {
				students[i].rank = i + 1;
				students[i].type = 2;
			}
			else;
	}
	sort(students, students + N, cmpM);//数学
	if (students[0].rank > 1) {
		students[0].rank = 1;
		students[0].type = 1;
	}
	for (int i = 1; i < N; i++) {
		if (students[i].math == students[i - 1].math)
			if (students[i].rank > students[i - 1].rank) {
				students[i].rank = students[i - 1].rank;
				students[i].type = 1;
			}
			else;
		else
			if (students[i].rank > i + 1) {
				students[i].rank = i + 1;
				students[i].type = 1;
			}
			else;
	}
	sort(students, students + N, cmpE);//英语
	if (students[0].rank > 1) {
		students[0].rank = 1;
		students[0].type = 0;
	}
	for (int i = 1; i < N; i++) {
		if (students[i].english == students[i - 1].english)
			if (students[i].rank > students[i - 1].rank) {
				students[i].rank = students[i - 1].rank;
				students[i].type = 0;
			}
			else;
		else
			if (students[i].rank > i + 1) {
				students[i].rank = i + 1;
				students[i].type = 0;
			}
			else;
	}

	int id, cursor;
	Student *result;
	for (int i = 0; i < M; i++) {
		scanf("%ld", &id);
		result = find(students, students + N, id);
		if (result == students + N)//STL里的二分查找熟练了会很方便
			printf("N/A\n");//原来不需要判断换行！
		else
			printf("%ld %c\n", result->rank, priority[result->type]);
	}

	//用下面这种查值写法验证了上面STL二分查找的结果是正确的
	//int id;
	//for (int i = 0; i < M; i++) {
	//	scanf("%ld", &id);
	//	int j = 0;
	//	for (; j < N; j++) {
	//		if (id == students[j].id)
	//			break;
	//	}
	//	if (j != N)
	//		printf("%d %c\n", students[j].rank, priority[students[j].type]);
	//	else
	//		printf("N/A\n");
	//}

	system("pause");
	return 0;
}
//写完之后测试点1 2出错了
//想了一个小时没找出来到底错在哪