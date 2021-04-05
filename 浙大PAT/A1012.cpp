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
	long rank;//��λ����id��һ������999999��rank
	int type;//priority, average:3, cLanguage:2, math:1, english:0
	bool operator == (const int &operand) {//��������Ҫ��Ϥ��
		return this->id == operand;
	}
};

bool cmpC(Student a, Student b) {//д���ϣ��������Ŀ���ϵ���������Լ��ⲿ�ִ��룬����û����ô������һ�������μ����S����
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
	//��priority˳�����Ĵ�
	sort(students, students + N, cmpA);//ƽ����
	students[0].rank = 1;
	for (int i = 1; i < N; i++)
		students[i].rank = students[i].average == students[i - 1].average ? students[i - 1].rank : i + 1;
	
	//�������������ο������ϳɺ���������û��Ҫ
	sort(students, students + N, cmpC);//C����
	if (students[0].rank > 1) {
		students[0].rank = 1;
		students[0].type = 2;
	}
	for (int i = 1; i < N; i++) {//���Լ�һ��д��������û������Ŀ����
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
	sort(students, students + N, cmpM);//��ѧ
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
	sort(students, students + N, cmpE);//Ӣ��
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
		if (result == students + N)//STL��Ķ��ֲ��������˻�ܷ���
			printf("N/A\n");//ԭ������Ҫ�жϻ��У�
		else
			printf("%ld %c\n", result->rank, priority[result->type]);
	}

	//���������ֲ�ֵд����֤������STL���ֲ��ҵĽ������ȷ��
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
//д��֮����Ե�1 2������
//����һ��Сʱû�ҳ������״�����