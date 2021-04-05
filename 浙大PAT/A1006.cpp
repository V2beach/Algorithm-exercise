#pragma warning(disable: 4996)
#include <cstdio>
#include <cstdlib>

struct Record {//不需要char time[8]了，学一下书上直接读hour minute second
	char id[15];
	int hour, minute, second;
};

int main(int argc, char *argv[]) {//找最早走的和最晚走的
	int M;
	scanf("%d", &M);
	M = M * 2;
	Record *records = new Record[M];

	Record maxrecord, minrecord;
	int maxno = -1, minno = -1;
	maxrecord.hour = 0;
	maxrecord.minute = 0;
	maxrecord.second = 0;
	minrecord.hour = 24;
	minrecord.minute = 60;
	minrecord.second = 60;

	for (int i = 0; i < M; i = i + 2) {
		scanf("%s %d:%d:%d %d:%d:%d", &records[i].id, &records[i].hour, &records[i].minute, &records[i].second, 
		&records[i + 1].hour, &records[i + 1].minute, &records[i + 1].second);
	}

	for (int i = 0; i < M; i++) {
		if (maxrecord.hour < records[i].hour) {
			maxrecord = records[i];
			maxno = i;
		}
		else if (maxrecord.hour == records[i].hour && maxrecord.minute < records[i].minute) {
			maxrecord = records[i];
			maxno = i;
		}
		else if (maxrecord.minute == records[i].minute && maxrecord.second < records[i].second) {
			maxrecord = records[i];
			maxno = i;
		}

		if (minrecord.hour > records[i].hour) {
			minrecord = records[i];
			minno = i;
		}
		else if (minrecord.hour == records[i].hour && minrecord.minute > records[i].minute) {
			minrecord = records[i];
			minno = i;
		}
		else if (minrecord.minute == records[i].minute && minrecord.second > records[i].second) {
			minrecord = records[i];
			minno = i;
		}
	}

	if (minno % 2 != 0)
		minno--;
	if (maxno % 2 != 0)
		maxno--;
	printf("%s %s", records[minno].id, records[maxno].id);

	system("pause");
	return 0;
}