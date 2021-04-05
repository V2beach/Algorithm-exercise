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
//10分钟搞定
//1.最后一个测试点只有一个元素；
//2.只需要判断过半即可，我这里是找出了最多的那个颜色，也并不会超时。