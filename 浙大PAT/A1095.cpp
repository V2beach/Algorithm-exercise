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
	long seconds;//��ʱ������¼����
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

void computeNumOfCars(vector<Record> records, int** queries, int* &numOfCars, int K) {//������һ���Լ���������char* argv[]�����*Ҫ��������������Ϊ����ʱһ��������ֻ�ܶ�Ӧһ����������֪��������������ˣ���׷����Щϸ֦ĩ�ڵĶ���ȷʵ��ˬ
	for (int i = 0, j = 0; i < K; i++) {//��ascending�ģ�����һ�����
		for (; j < records.size(); j += 2) {
			long seconds1 = queries[i][0] * 3600 + queries[i][1] * 60 + queries[i][2],
				seconds2 = records[j].hour * 3600 + records[j].minute * 60 + records[j].second,
				seconds3 = records[j + 1].hour * 3600 + records[j + 1].minute * 60 + records[j + 1].second;
			if (seconds1 >= seconds2 && seconds1 < seconds3) {
				numOfCars[i]++;
				break;
			}
			else if (seconds1 < seconds2) break;
			else continue;//���������query��record֮�ڣ��Ǿ�break����һ��query����query��recordС��Ҳbreak����һ��query����query��record�󣬾�����һ��record���ȣ�����break
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
	for (int i = 0; i < N; i++) {//��һ�θ�A1016һ�����а취�Ż���
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
		if (strcmp(records[i].plate, records[i + 1].plate) != 0 && !isValidRecords.empty() || i == N - 1) {//Ϊʲô�����i + 1���ᱨ������
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
//��ʧ���ˣ����������Ե��벻������ʲô��
//����ˢ��������ٻ�����������
//�����̬ը�ˣ�Խ��Խը��״ֻ̬��Խ��Խ��