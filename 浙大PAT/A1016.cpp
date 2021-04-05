#pragma warning(disable: 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct Record {
	char customer[21], type[9];//on-line��off-lineҪ��ԣ���ʵ���ǽӵ绰/�ҵ绰��Ӣ��ˮƽ����...
	int month, day, hour, minute;
};

bool cmp(Record a, Record b) {
	int c = strcmp(a.customer, b.customer);
	if (c != 0) return c < 0;//�ֵ����С���󣬲���ֱ�ӷ���integerֵ
	else if (a.month != b.month) return a.month < b.month;
	else if (a.day != b.day) return a.day < b.day;
	else if (a.hour != b.hour) return a.hour < b.hour;
	else if (a.minute != b.minute) return a.minute < b.minute;
	return strcmp(a.type, b.type) > 0;
}

int computeCharge(Record a, Record b, int rate[25]) {//��������������Ӽ�̫���ˣ�׼ȷ�ж����֮��ֱ�ӳ˱ȽϺðɣ���������Ӽ�ȷʵ�򵥣�������������ַ����Ļ����д���ˣ��ڿ��Ի������ʱ��͸�ѡ���Һ�ʱ������̫����㷨��
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
	if (a.day != b.day) {//������ͬһ����
		if (a.hour < b.hour || a.hour == b.hour && a.minute < b.minute) {//b��ʱ������ֵ�ϱ�a��
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
	bool isValid = true;//��һ�������������Ž�
	int previous = 0;
	vector<Record> validRecords;
	char *name = records[0].customer;
	for (int i = 0; i < N; i++) {
		if (strcmp(records[i].type, "on-line") == 0) {
			if (isValid) {//��Ч��ͨ����¼֮�󣬶���online��������
				isValid = false;
				previous = i;
			}
			else//�ӵ绰��¼�����online���α�ָ������
				previous = i;
		}
		else {
			if (isValid);//��Ч��ͨ����¼֮�����offline�������
			else {//�ӵ绰��¼֮�󣬶���offline����һ����Чͨ����¼
				isValid = true;
				validRecords.push_back(records[previous]);
				validRecords.push_back(records[i]);
			}
		}
		//���Ч�ĸ�bug�취����ֱ�Ӵ�ӡ���������Ա�������
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
				if (validRecords.size() == 0)//ͨ�����ϵĲ��Ե㣬����������©����̫���ˡ�
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
�һ�������Сʱ�������ҵ����������ڣ���Ĭ����b.time����ֵ��һ������a.time������Զ��׼��Ĵ���ʵ����̫���ˣ�
����Ⱪ¶���ܶ����⣬��0��ʱ�ҵ�һʱ�������PAT��OJϵͳ�����⣬һ����Ϊ̫���ţ�������Ϊ̫���裬���ⲿѰ������ͱ������Լ�����bug��
��ѵ������Ҫ�������OJ��IDE�����Ǻ��޵����ҷǳ���רҵ����Ϊ�������ᰴ���S���ǵľ��������������һ�顣
���Ե㣬��������OJ��ʱ�򣬱��������ںв��ԣ������ظ����������׺в��Զ��Ƿǳ���Ҫ��������
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