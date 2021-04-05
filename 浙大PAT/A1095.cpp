#pragma warning(disable: 4996)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Record {
	char plate[8];//capital letters and 1-digit numbers
	int hour, minute, second;
	char status[4];//in-out
};

struct Car {
	char *plate;
	long seconds;//暂时决定记录秒数
	Car(char *plate, long seconds) {
		this->plate = plate;
		this->seconds = seconds;
	}
};

bool cmp1(Record a, Record b) {
	int c = strcmp(a.plate, b.plate);
	if (c != 0) return c < 0;
	else if (a.hour != b.hour) return a.hour < b.hour;
	else if (a.minute != b.minute) return a.minute < b.minute;
	else return a.second < b.second;
}

bool cmp2(Car a, Car b) {
	return a.seconds > b.seconds;
}

int computeSeconds(vector<Record> records) {
	int seconds = 0;
	for (int i = 0; i < records.size(); i += 2)
		seconds += (records[i + 1].second - records[i].second) + 60 * (records[i + 1].minute - records[i].minute) + 3600 * (records[i + 1].hour - records[i].hour);
	return seconds;
}

void computeNumOfCars(vector<Record> records, int** queries, int* &numOfCars, int K) {//发现了一个自己的理解错误，char* argv[]这里的*要靠着类型名，因为传参时一个类型名只能对应一个变量，我知道大概是我神经质了，但追求这些细枝末节的东西确实很爽
	for (int i = 0, j = 0; i < K; i++) {//是ascending的，遍历一遍就行
		for (; j < records.size(); j += 2) {
			long seconds1 = queries[i][0] * 3600 + queries[i][1] * 60 + queries[i][2],
				seconds2 = records[j].hour * 3600 + records[j].minute * 60 + records[j].second,
				seconds3 = records[j + 1].hour * 3600 + records[j + 1].minute * 60 + records[j + 1].second;
			if (seconds1 >= seconds2 && seconds1 < seconds3) {
				numOfCars[i]++;
				break;
			}
			else if (seconds1 < seconds2) break;
			else continue;//三种情况，query在record之内，那就break让下一个query来；query比record小，也break让下一个query来；query比record大，就让下一个record来比，不用break
		}
	}
}

int main(int argc, char* argv[]) {
	int N, K;
	scanf("%d %d", &N, &K);
	Record *records = new Record[N];
	for (int i = 0; i < N; i++)
		scanf("%s %d:%d:%d %s", records[i].plate, &records[i].hour, &records[i].minute, &records[i].second, records[i].status);
	sort(records, records + N, cmp1);
	int **queries = new int*[K];
	for (int i = 0; i < K; i++) {
		queries[i] = new int[3];
		scanf("%d:%d:%d", &queries[i][0], &queries[i][1], &queries[i][2]);
	}
	int previous = 0;
	bool isValid = true;
	vector<Car> cars;
	vector<Record> isValidRecords;
	int *numOfCars = new int[K]();
	for (int i = 0; i < N; i++) {//这一段跟A1016一样，有办法优化吗
		if (strcmp(records[i].status, "in") == 0) {
			if (isValid) {
				previous = i;
				isValid = false;
			}
			else previous = i;
		}
		else {
			if (isValid);
			else {
				isValidRecords.push_back(records[previous]);
				isValidRecords.push_back(records[i]);
				isValid = true;
			}
		}
		if (strcmp(records[i].plate, records[i + 1].plate) != 0 && !isValidRecords.empty() || i == N - 1) {//为什么这里的i + 1不会报错？？？
			Car car(records[i].plate, computeSeconds(isValidRecords));
			cars.push_back(car);
			computeNumOfCars(isValidRecords, queries, numOfCars, K);
			isValidRecords.clear();
		}
	}
	for (int i = 0; i < K; i++)
		printf("%d\n", numOfCars[i]);
	sort(cars.begin(), cars.end(), cmp2);
	int seconds = cars[0].seconds;
	for (int i = 0; i < cars.size(); i++) {
		if (seconds == cars[i].seconds)
			printf("%s ", cars[i].plate);
		else break;
	}
	int hour, minute, second;
	hour = seconds / 3600;
	minute = seconds / 60 % 60;
	second = seconds % 60;
	printf("%02d:%02d:%02d\n", hour, minute, second);
	system("pause");
	return 0;
}
//我失败了，后面俩测试点想不出来是什么，
//等我刷完第六章再回来重新做吧
//真的心态炸了，越看越炸，状态只会越来越差