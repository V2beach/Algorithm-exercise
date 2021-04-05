#pragma warning(disable: 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct Record {
	char customer[21], type[9];//on-line和off-line要配对，其实就是接电话/挂电话，英文水平堪忧...
	int month, day, hour, minute;
};

bool cmp(Record a, Record b) {
	int c = strcmp(a.customer, b.customer);
	if (c != 0) return c < 0;//字典序从小到大，不能直接返回integer值
	else if (a.month != b.month) return a.month < b.month;
	else if (a.day != b.day) return a.day < b.day;
	else if (a.hour != b.hour) return a.hour < b.hour;
	else if (a.minute != b.minute) return a.minute < b.minute;
	return strcmp(a.type, b.type) > 0;
}

int computeCharge(Record a, Record b, int rate[25]) {//按书上那种逐分钟加太慢了，准确判断情况之后直接乘比较好吧，但是逐分钟加确实简单，如果我早用那种方法的话早就写完了，在考试或比赛的时候就该选简单且耗时并不差太多的算法！
	int cents = 0;
	if (a.hour == b.hour)
		cents = rate[a.hour] * (b.minute - a.minute);
	else if (a.hour == b.hour)
		cents = rate[a.hour] * (60 - a.minute) + rate[b.hour] * b.minute;
	else {
		cents = rate[a.hour] * (60 - a.minute) + rate[b.hour] * b.minute;
		for (int i = a.hour + 1; i < b.hour; i++)
			cents += rate[i] * 60;
	}
	if (a.day != b.day) {//不是在同一天里
		if (a.hour < b.hour || a.hour == b.hour && a.minute < b.minute) {//b的时间在数值上比a大
			cents += (b.day - a.day) * rate[24] * 60;
		}
		else {
			cents = rate[a.hour] * (60 - a.minute) + rate[b.hour] * b.minute;
			for (int i = a.hour + 1; i < 24; i++)
				cents += rate[i] * 60;
			for (int i = 0; i < b.hour; i++)
				cents += rate[i] * 60;
			cents += (b.day - a.day - 1) * rate[24] * 60;
		}
	}
	return cents;
}

int computeMinutes(Record a, Record b) {
	return (b.day - a.day) * 24 * 60 + (b.hour - a.hour) * 60 + (b.minute - a.minute);
}

int main(int argc, char *argv[]) {
	int rate[25];
	for (int i = 0; i < 24; i++)
		scanf("%d", &rate[i]);
	rate[24] = accumulate(rate, rate + 24, 0);
	int N;
	scanf("%d", &N);
	Record *records = new Record[N];
	for (int i = 0; i < N; i++)
		scanf("%s %d:%d:%d:%d %s", records[i].customer, &records[i].month, &records[i].day, &records[i].hour, &records[i].minute, records[i].type);
	sort(records, records + N, cmp);
	bool isValid = true;//别一上来就想找最优解
	int previous = 0;
	vector<Record> validRecords;
	char *name = records[0].customer;
	for (int i = 0; i < N; i++) {
		if (strcmp(records[i].type, "on-line") == 0) {
			if (isValid) {//有效的通话记录之后，读到online是正常的
				isValid = false;
				previous = i;
			}
			else//接电话记录后跟了online，游标指到后者
				previous = i;
		}
		else {
			if (isValid);//有效的通话记录之后跟了offline，错误的
			else {//接电话记录之后，读到offline构成一条有效通话记录
				isValid = true;
				validRecords.push_back(records[previous]);
				validRecords.push_back(records[i]);
			}
		}
		//最高效的改bug办法还是直接打印变量，调试比这样慢
		//printf("\n");
		//for (int i = 0; i < N; i++)
		//	printf("%s %d:%d:%d:%d %s\n", records[i].customer, records[i].month, records[i].day, records[i].hour, records[i].minute, records[i].type);
		//printf("\n");
		//printf("\n");
		//for (int i = 0; i < validRecords.size(); i++)
		//	printf("%s %d:%d:%d:%d %s\n", validRecords[i].customer, validRecords[i].month, validRecords[i].day, validRecords[i].hour, validRecords[i].minute, validRecords[i].type);
		//printf("\n");
		if (i < N)
			if (strcmp(name, records[i + 1].customer) != 0 || i == N - 1) {
				isValid = true;
				name = records[i + 1].customer;
				if (validRecords.size() == 0)//通过书上的测试点，发现了致命漏洞，太蠢了。
					continue;
				int cent = 0;
				int cents = 0;
				printf("%s %02d\n", records[i].customer, records[i].month);
				for (int j = 0; j < validRecords.size(); j += 2) {
					cent = computeCharge(validRecords[j], validRecords[j + 1], rate);
					cents += cent;
					printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", validRecords[j].day, validRecords[j].hour, validRecords[j].minute, validRecords[j + 1].day, validRecords[j + 1].hour, validRecords[j + 1].minute, computeMinutes(validRecords[j], validRecords[j + 1]), cent / 100.0);
				}
				printf("Total amount: $%.2lf\n", cents / 100.0);
				//if (i != N - 2)
				//	printf("\n");
				validRecords.clear();
			}
	}

	system("pause");
	return 0;
}
/*
我花了三个小时，终于找到了问题所在，我默认了b.time在数值上一定大于a.time，如此显而易见的错误！实在是太蠢了，
这个题暴露出很多问题，判0分时我第一时间想的是PAT的OJ系统有问题，一是因为太自信，二是因为太懒惰，从外部寻找问题就避免了自己修正bug。
教训——不要随便质疑OJ和IDE，这是毫无道理且非常不专业的行为，这道题会按柳婼她们的精简的做法重新做一遍。
测试点，在做这种OJ的时候，编数据做黑盒测试，快速重复读代码做白盒测试都是非常重要的能力。
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
5
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:02:00:02 off-line

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
4
aaa 01:01:22:30 off-line
aaa 01:02:23:50 off-line
aaa 01:03:22:30 on-line
aaa 01:11:23:50 on-line

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
4
aaa 12:01:22:30 on-line
aaa 12:02:23:50 off-line
aaa 12:03:22:30 off-line
aaa 12:11:23:50 off-line

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
2
aaa 01:01:00:30 on-line
aaa 01:01:00:30 off-line


0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line

10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
4
CYJJ 01:01:07:00 off-line
CYJJ 01:01:05:59 on-line
CYJJ 01:01:05:00 on-line
CYJJ 01:01:07:59 off-line

10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
18
CYLL 01:01:06:01 on-line
CYLL 01:01:07:00 off-line
CYLL 01:01:08:03 on-line
CYLL 01:01:08:09 off-line
CYLL 01:01:08:09 on-line
CYLL 01:02:00:01 off-line
CYLL 01:28:15:41 on-line
CYLL 01:29:02:24 on-line
CYLL 01:30:23:59 off-line
CYLL 01:30:24:59 off-line
CYLL 01:30:25:00 off-line
CYLL 01:30:25:25 off-line
MQ 01:01:06:01 on-line
MQ 01:02:03:04 on-line
MQ 01:03:04:05 on-line
MQ 01:03:04:06 off-line
YF 01:02:03:04 on-line
YF 01:02:03:05 on-line
*/