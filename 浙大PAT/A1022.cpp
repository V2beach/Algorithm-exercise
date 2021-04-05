#pragma warning(disable: 4996)
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
map<string, set<int>> titles, authors, keywords, publishers, years;
void query(map<string, set<int>>& info, string& type) {//不加引用会超时，字符串及map的形参传递较慢
	if (info.find(type) == info.end()) cout << "Not Found" << endl;
	else {
		set<int>::iterator it;
		for (it = info[type].begin(); it != info[type].end(); it++)
			printf("%07d\n", *it);//cout << *it << endl;
	}
}
int main(int argc, char* argv[]) {
	int N, M, id;
	//ios::sync_with_stdio(false);//不能随便加，加了反而报运行超时！
	cin >> N;
	string title, author, keyword, publisher, year;
	for (int i = 0; i < N; i++) {
		cin >> id; getchar();//id
		getline(cin, title);//书名
		titles[title].insert(id);
		getline(cin, author);//作者
		authors[author].insert(id);
		while (cin >> keyword) {//关键词，>>重载后返回值在没有读入错误时返回非零值
			keywords[keyword].insert(id);
			if (getchar() == '\n') break;//读入一个空格，这样处理很漂亮
		}
		getline(cin, publisher);//出版社
		publishers[publisher].insert(id);
		getline(cin, year);//年份
		years[year].insert(id);
	}
	cin >> M;
	int typen;
	string type;
	for (int i = 0; i < M; i++) {
		scanf("%d: ", &typen);
		getline(cin, type);//学习一下这个读入
		cout << typen << ": " << type << endl;
		if (typen == 1) query(titles, type);
		else if (typen == 2) query(authors, type);
		else if (typen == 3) query(keywords, type);
		else if (typen == 4) query(publishers, type);
		else query(years, type);
	}
	system("pause");
	return 0;
}
//大型模拟，经典图书管理，冲，一小时内写一个图书管理代码。
//用vector写的全部超时，set也不行，本地跑得通，上了OJ就是跑不通，
//思想是跟晴神基本一样的，但我学习了一下他的写法，他写得非常漂亮，
//我有这种抽象成query函数的想法，但是并不能非常顺畅的实现，
//map的使用和写代码的灵活程度也都高我一筹，学习一个先进思想。
//艹，我最后发现，是因为用了ios::sync_with_stdio(false)，本来就写对了，
//习惯性地加上了，找了整整一个下午bug，上午一个小时就写完了，一天又白瞎，
//他妈的备注一下，ios::sync_with_stdio(false)，还有注意格式printf(%07d)。
//整理一下ios::sync_with_stdio(false)具体如何取消cin和scanf同步，
//并且完整地整理读写数据的所有知识，C++的文件读写，标准读写，和C的区别等。
//#pragma warning(disable: 4996)
//#include <iostream>
//#include <set>
//#include <string>
//#include <unordered_map>
//#include <algorithm>
//
//using namespace std;
//
//unordered_map<string, set<long>> titles;//80characters
//unordered_map<string, set<long>> authors;//80characters 1book1author
//unordered_map<string, set<long>> keywords;//10characters 5keywords 1000total
//unordered_map<string, set<long>> publishers;//80characters 1000total
//unordered_map<string, set<long>> years;//4-digit number
//unordered_map<string, set<long>>::iterator it;
//
//int main(int argc, char* argv[]) {
//	int N, M;
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		string title, author, keyword, publisher, year;
//
//		//id
//		long id;
//		cin >> id;
//		getchar();
//
//		//书名
//		getline(cin, title);
//		it = titles.find(title);
//		if (it == titles.end()) {
//			set<long> ids;
//			ids.insert(id);
//			titles.insert(pair<string, set<long>>(title, ids));
//		}
//		else {
//			it->second.insert(id);
//		}
//
//		//作者
//		getline(cin, author);
//		it = authors.find(author);
//		if (it == authors.end()) {
//			set<long> ids;
//			ids.insert(id);
//			authors.insert(pair<string, set<long>>(author, ids));
//		}
//		else {
//			it->second.insert(id);
//		}
//
//		//关键词
//		getline(cin, keyword);
//		int prev = 0;
//		string substring;
//		for (int j = 0; j < keyword.size(); j++) {
//			if (keyword[j] == ' ') {
//				substring = keyword.substr(prev, j - prev);
//				it = keywords.find(substring);
//				if (it == keywords.end()) {
//					set<long> ids;
//					ids.insert(id);
//					keywords.insert(pair<string, set<long>>(substring, ids));
//				}
//				else {
//					it->second.insert(id);
//				}
//				prev = j + 1;
//			}
//		}
//		substring = keyword.substr(prev, keyword.size() - prev);//最后一个，图省事就直接拿出来了
//		it = keywords.find(substring);
//		if (it == keywords.end()) {
//			set<long> ids;
//			ids.insert(id);
//			keywords.insert(pair<string, set<long>>(substring, ids));
//		}
//		else {
//			it->second.insert(id);
//		}
//
//		//出版社
//		getline(cin, publisher);
//		it = publishers.find(publisher);
//		if (it == publishers.end()) {
//			set<long> ids;
//			ids.insert(id);
//			publishers.insert(pair<string, set<long>>(publisher, ids));
//		}
//		else {
//			it->second.insert(id);
//		}
//
//		getline(cin, year);
//		it = years.find(year);
//		if (it == years.end()) {
//			set<long> ids;
//			ids.insert(id);
//			years.insert(pair<string, set<long>>(year, ids));
//		}
//		else {
//			it->second.insert(id);
//		}
//		//cout << "TEST: " << id << " " << title << " " << author << " " << publisher << " " << year << " " << endl;
//	}
//	cin >> M;
//	string type;
//	int typenum;
//	for (int i = 0; i < M; i++) {
//		cin >> type;
//		getchar();//space
//		typenum = type[0] - '0';
//		string title, author, keyword, publisher, year;
//		set<long>::iterator iter;
//		switch (typenum) {
//		case 1:
//			getline(cin, title);
//			cout << type << " " << title << endl;
//			it = titles.find(title);
//			if (it != titles.end()) {
//				//sort(it->second.begin(), it->second.end());
//				for (iter = it->second.begin(); iter != it->second.end(); iter++) {
//					printf("%07ld\n", *iter);
//				}
//			}
//			else {
//				cout << "Not Found" << endl;
//			}
//			break;
//		case 2:
//			getline(cin, author);
//			cout << type << " " << author << endl;
//			it = authors.find(author);
//			if (it != authors.end()) {
//				//sort(it->second.begin(), it->second.end());
//				for (iter = it->second.begin(); iter != it->second.end(); iter++) {
//					printf("%07ld\n", *iter);
//				}
//			}
//			else {
//				cout << "Not Found" << endl;
//			}
//			break;
//		case 3:
//			getline(cin, keyword);
//			cout << type << " " << keyword << endl;
//			it = keywords.find(keyword);
//			if (it != keywords.end()) {
//				//sort(it->second.begin(), it->second.end());
//				for (iter = it->second.begin(); iter != it->second.end(); iter++) {
//					printf("%07ld\n", *iter);
//				}
//			}
//			else {
//				cout << "Not Found" << endl;
//			}
//			break;
//		case 4:
//			getline(cin, publisher);
//			cout << type << " " << publisher << endl;
//			it = publishers.find(publisher);
//			if (it != publishers.end()) {
//				//sort(it->second.begin(), it->second.end());
//				for (iter = it->second.begin(); iter != it->second.end(); iter++) {
//					printf("%07ld\n", *iter);
//				}
//			}
//			else {
//				cout << "Not Found" << endl;
//			}
//			break;
//		case 5:
//			getline(cin, year);
//			cout << type << " " << year << endl;
//			it = years.find(year);
//			if (it != years.end()) {
//				//sort(it->second.begin(), it->second.end());
//				for (iter = it->second.begin(); iter != it->second.end(); iter++) {
//					printf("%07ld\n", *iter);
//				}
//			}
//			else {
//				cout << "Not Found" << endl;
//			}
//			break;
//		default:
//			cout << "Go Fuck Yourself" << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}