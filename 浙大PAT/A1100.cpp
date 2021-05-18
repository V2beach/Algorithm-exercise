#pragma warning(disable: 4996)
#include <map>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//干脆用全局变量了
string marsLow[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string marsHigh[13] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
map<string, int> earthLow;
map<string, int> earthHigh;
map<string, int>::iterator it;

int toEarth(string mars) {//字符串转十三进制再转十进制
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
		if (it == earthLow.end()) {//是13的倍数，服了，这是英文习惯，要灵活转变思路！
			it = earthHigh.find(mars.substr(0, index));
			earth = it->second * 13;
		}
		else earth = it->second;
	}
	return earth;
}

string toMars(string earth) {//十进制转十三进制再转字符串
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
	init();//初始化mars表
	int N;
	ios::sync_with_stdio(false);
	cin >> N;
	getchar();
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");
	for (int i = 0; i < N; i++) {
		string input;
		/*
			正常输入输出
		*/
		getline(cin, input);
		if (isdigit(input[0])) cout << toMars(input) << endl;
		else cout << toEarth(input) << endl;
		/*
			文件输入输出
		*/
		//得到所有的测试用例
		outputFile << i << endl;
		outputFile << toMars(to_string(i)) << endl;
		//开始遍历测试全部用例，和柳婼代码跑出来的结果使用notepad++的compare插件进行逐个比对，测试文件已经上传到我的FTP服务器
		getline(inputFile, input);
		if (isdigit(input[0])) outputFile << toMars(input) << endl;
		else outputFile << toEarth(input) << endl;
	}
	system("pause");
	return 0;
}
//变量名起了半个小时。
//我从0~169自己测试全都对了，OJ就是过不了！
//找了两个小时没找到问题到底出在哪后决定，
//学习一下文件操作，我把169x2个情况全部打印一遍看看和正确答案的区别，
//如果确实没有区别，那问题就不在我，这个题暂时跳过，或者问一问群里的兄弟们。
//没人回，暂时放弃了，把所有文件传到FTP上面，之后写题解博客的时候会把链接放在这篇里面。