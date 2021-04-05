#pragma warning(disable: 4996)
#include <map>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	long pixel;
	int N, M, pax = 0, paxindex;
	ios::sync_with_stdio(false);
	cin >> N >> M;
	map<long, int> pixels;
	map<long, int>::iterator it;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> pixel;
			it = pixels.find(pixel);
			if (it == pixels.end())
				pixels.insert(pair<long, int>(pixel, 1));
			else
				it->second++;
		}
	}
	for (it = pixels.begin(); it != pixels.end(); it++) {
		if (it->second > pax) {
			pax = it->second;
			paxindex = it->first;
		}
	}
	cout << paxindex << endl;
	system("pause");
	return 0;
}
//10���Ӹ㶨
//1.���һ�����Ե�ֻ��һ��Ԫ�أ�
//2.ֻ��Ҫ�жϹ��뼴�ɣ����������ҳ��������Ǹ���ɫ��Ҳ�����ᳬʱ��