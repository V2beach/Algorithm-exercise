#pragma warning(disable: 4996)
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Person{
	long long id;
	int virtue;
	int talent;
	int total;
};

bool cmp(Person a, Person b) {
	if (a.total != b.total) return a.total > b.total;
	else if (a.virtue != b.virtue) return a.virtue > b.virtue;
	else return a.id < b.id;
}

int main(int argc, char *argv[]) {
	long N;
	int L, H;
	scanf("%ld %d %d", &N, &L, &H);
	vector<Person> people1;
	vector<Person> people2;
	vector<Person> people3;
	vector<Person> people4;

	for (int i = 0; i < N; i++) {
		Person person;
		scanf("%lld %d %d", &person.id, &person.virtue, &person.talent);
		person.total = person.virtue + person.talent;
		if (person.virtue >= L && person.talent >= L)//及格线
			if (person.virtue >= H && person.talent >= H)//才德全尽
				people1.push_back(person);
			else if (person.virtue >= H)//德胜才
				people2.push_back(person);
			else if (person.virtue >= person.talent)//才德兼亡但德胜才的庸人
				people3.push_back(person);
			else//小人
				people4.push_back(person);
		else;//不及格
	}

	sort(people1.begin(), people1.end(), cmp);
	sort(people2.begin(), people2.end(), cmp);
	sort(people3.begin(), people3.end(), cmp);
	sort(people4.begin(), people4.end(), cmp);

	printf("%ld", people1.size() + people2.size() + people3.size() + people4.size());
	for (int i = 0; i < people1.size(); i++)
		printf("\n%lld %d %d", people1[i].id, people1[i].virtue, people1[i].talent);
	for (int i = 0; i < people2.size(); i++)
		printf("\n%lld %d %d", people2[i].id, people2[i].virtue, people2[i].talent);
	for (int i = 0; i < people3.size(); i++)
		printf("\n%lld %d %d", people3[i].id, people3[i].virtue, people3[i].talent);
	for (int i = 0; i < people4.size(); i++)
		printf("\n%lld %d %d", people4[i].id, people4[i].virtue, people4[i].talent);
	system("pause");
	return 0;
}
//光速完成