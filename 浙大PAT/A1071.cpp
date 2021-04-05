#pragma warning(disable: 4996)
#include <map>
#include <string>
#include <iostream>

using namespace std;

bool isAlphanumeric(char &character) {
	if (character >= '0' && character <= '9')
		return true;
	else if (character >= 'a' && character <= 'z')
		return true;
	else if (character >= 'A' && character <= 'Z') {
		character = character - 'A' + 'a';
		return true;
	}
	return false;
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	string testcase;
	getline(cin, testcase);//注意读一行要用getline，老是忘记
	map<string, long> words;
	map<string, long>::iterator it;
	string substring;
	long index = 0, prev = 0;
	for (; index < testcase.size(); index++) {
		if (isAlphanumeric(testcase[index])) {
			prev = index;
			while (isAlphanumeric(testcase[++index]));//找到之后的第一个non-alphanumeric
			substring = testcase.substr(prev, index - prev);
			it = words.find(substring);
			if (it == words.end())
				words.insert(pair<string, long>(substring, 1));
			else
				it->second++;
		}
	}
	long sax = 0;
	for (it = words.begin(); it != words.end(); it++) {
		//cout << it->first << " " << it->second << endl;
		if (it->second > sax) {
			sax = it->second;
			substring = it->first;
		}
	}
	cout << substring << " " << sax << endl;
	system("pause");
	return 0;
}
//光速完成