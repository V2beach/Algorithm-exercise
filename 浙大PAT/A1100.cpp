#pragma warning(disable: 4996)
#include <map>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//�ɴ���ȫ�ֱ�����
string marsLow[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string marsHigh[13] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
map<string, int> earthLow;
map<string, int> earthHigh;
map<string, int>::iterator it;

int toEarth(string mars) {//�ַ���תʮ��������תʮ����
	int earth = 0, index = 0;
	for (; index < mars.size(); index++)
		if (mars[index] == ' ')
			break;
	if (index != mars.size()) {
		it = earthHigh.find(mars.substr(0, index));
		earth = it->second * 13;
		it = earthLow.find(mars.substr(index + 1));
		earth += it->second;
	}
	else {
		it = earthLow.find(mars.substr(0, index));
		if (it == earthLow.end()) {//��13�ı��������ˣ�����Ӣ��ϰ�ߣ�Ҫ���ת��˼·��
			it = earthHigh.find(mars.substr(0, index));
			earth = it->second * 13;
		}
		else earth = it->second;
	}
	return earth;
}

string toMars(string earth) {//ʮ����תʮ��������ת�ַ���
	string mars;
	int res = stoi(earth);
	if (res == 0) return marsLow[res];
	if (res % 13 == 0) return marsHigh[res / 13];
	mars = marsLow[res % 13] + mars;
	res /= 13;
	if (res) mars = marsHigh[res % 13] + " " + mars;
	return mars;
}

void init() {
	for (int i = 0; i < 13; i++)
		earthLow.insert(pair<string, int>(marsLow[i], i));
	for (int i = 0; i < 13; i++)
		earthHigh.insert(pair<string, int>(marsHigh[i], i));
}

int main(int argc, char* argv[]) {
	init();//��ʼ��mars��
	int N;
	ios::sync_with_stdio(false);
	cin >> N;
	getchar();
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");
	for (int i = 0; i < N; i++) {
		string input;
		/*
			�����������
		*/
		getline(cin, input);
		if (isdigit(input[0])) cout << toMars(input) << endl;
		else cout << toEarth(input) << endl;
		/*
			�ļ��������
		*/
		//�õ����еĲ�������
		outputFile << i << endl;
		outputFile << toMars(to_string(i)) << endl;
		//��ʼ��������ȫ�������������S�����ܳ����Ľ��ʹ��notepad++��compare�����������ȶԣ������ļ��Ѿ��ϴ����ҵ�FTP������
		getline(inputFile, input);
		if (isdigit(input[0])) outputFile << toMars(input) << endl;
		else outputFile << toEarth(input) << endl;
	}
	system("pause");
	return 0;
}
//���������˰��Сʱ��
//�Ҵ�0~169�Լ�����ȫ�����ˣ�OJ���ǹ����ˣ�
//��������Сʱû�ҵ����⵽�׳����ĺ������
//ѧϰһ���ļ��������Ұ�169x2�����ȫ����ӡһ�鿴������ȷ�𰸵�����
//���ȷʵû������������Ͳ����ң��������ʱ������������һ��Ⱥ����ֵ��ǡ�
//û�˻أ���ʱ�����ˣ��������ļ�����FTP���棬֮��д��ⲩ�͵�ʱ�������ӷ�����ƪ���档