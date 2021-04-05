#pragma warning(disable: 4996)
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
map<string, set<int>> titles, authors, keywords, publishers, years;
void query(map<string, set<int>>& info, string& type) {//�������ûᳬʱ���ַ�����map���βδ��ݽ���
	if (info.find(type) == info.end()) cout << "Not Found" << endl;
	else {
		set<int>::iterator it;
		for (it = info[type].begin(); it != info[type].end(); it++)
			printf("%07d\n", *it);//cout << *it << endl;
	}
}
int main(int argc, char* argv[]) {
	int N, M, id;
	//ios::sync_with_stdio(false);//�������ӣ����˷��������г�ʱ��
	cin >> N;
	string title, author, keyword, publisher, year;
	for (int i = 0; i < N; i++) {
		cin >> id; getchar();//id
		getline(cin, title);//����
		titles[title].insert(id);
		getline(cin, author);//����
		authors[author].insert(id);
		while (cin >> keyword) {//�ؼ��ʣ�>>���غ󷵻�ֵ��û�ж������ʱ���ط���ֵ
			keywords[keyword].insert(id);
			if (getchar() == '\n') break;//����һ���ո����������Ư��
		}
		getline(cin, publisher);//������
		publishers[publisher].insert(id);
		getline(cin, year);//���
		years[year].insert(id);
	}
	cin >> M;
	int typen;
	string type;
	for (int i = 0; i < M; i++) {
		scanf("%d: ", &typen);
		getline(cin, type);//ѧϰһ���������
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
//����ģ�⣬����ͼ������壬һСʱ��дһ��ͼ�������롣
//��vectorд��ȫ����ʱ��setҲ���У������ܵ�ͨ������OJ�����ܲ�ͨ��
//˼���Ǹ��������һ���ģ�����ѧϰ��һ������д������д�÷ǳ�Ư����
//�������ֳ����query�������뷨�����ǲ����ܷǳ�˳����ʵ�֣�
//map��ʹ�ú�д��������̶�Ҳ������һ�ѧϰһ���Ƚ�˼�롣
//ܳ��������֣�����Ϊ����ios::sync_with_stdio(false)��������д���ˣ�
//ϰ���Եؼ����ˣ���������һ������bug������һ��Сʱ��д���ˣ�һ���ְ�Ϲ��
//����ı�עһ�£�ios::sync_with_stdio(false)������ע���ʽprintf(%07d)��
//����һ��ios::sync_with_stdio(false)�������ȡ��cin��scanfͬ����
//���������������д���ݵ�����֪ʶ��C++���ļ���д����׼��д����C������ȡ�
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
//		//����
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
//		//����
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
//		//�ؼ���
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
//		substring = keyword.substr(prev, keyword.size() - prev);//���һ����ͼʡ�¾�ֱ���ó�����
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
//		//������
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