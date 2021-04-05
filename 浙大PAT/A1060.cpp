#pragma warning(disable: 4996)
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string toSci(string str, int valid) {//写不下去的时候硬着头皮写
	string sci;
	//要去除前导0
	while (str[0] == '0')
		str.erase(str.begin());
	if (str[0] == '.' || str.size() <= 0) {//先处理整数部分为零的情况
		int nonZero = -1, zhishu = 0;
		if (str.size() <= 0) sci = "0";
		else {
			for (int i = 2; i < str.size(); i++)//找到第一个不为零的位置
				if (str[i] != '0') {
					nonZero = i;
					break;
				}
			if (nonZero == -1) sci = "0";//找不到就还是0
			else {//不是0的情况都在这里
				zhishu = -(nonZero - 1);//找到了就获得了有效的数字字符串
				sci = str.substr(nonZero);//应该可以截取到最后
			}
		}
		int siz = sci.size();
		if (sci.size() > valid)
			sci = sci.substr(0, valid);
		else if (sci.size() < valid)//位数不够就凑0
			for (int i = 0; i < valid - siz; i++)//千万不要把一个动态的数放到条件里比如sci.size()
				sci += "0";
		else;
		sci = "0." + sci + "*10^" + to_string(zhishu);//sci是有效位，zhishu是指数
	}
	else {//再处理一开始做的那种情况
		int slen = str.size();
		for (int i = 0; i < slen; i++)//找到.，如果找不到就没小数位
			if (str[i] == '.') {
				str.erase(str.begin() + i);
				slen = i;
			}
		sci = str.substr(0, min(valid, int(str.size())));
		int siz = sci.size();
		if (sci.size() < valid)
			for (int i = 0; i < valid - siz; i++)
				sci += "0";
		sci = "0." + sci + "*10^" + to_string(slen);
	}
	return sci;
}

int main(int argc, char* argv[]) {
	int N;//精度，或者说有效位数
	string A, B, C, D;
	ios::sync_with_stdio(false);
	cin >> N >> A >> B;
	C = toSci(A, N);
	D = toSci(B, N);
	if (C == D) cout << "YES " << C;
	else cout << "NO " << C << " " << D;
	system("pause");
	return 0;
}
//测试点4实在是太坑了，是0001.1这种形式...备注，可以优化后作为科学计数法的模板。
//原先用的是下面的做法，只考虑了题目SampleInput SampleOutput，又被样例给误导了，没有好好读题，
//一次跑通，但只有0 1 2 5测试点正确，3 4 6测试点是错的，我估计是0.xxx的数据。
//之后决定先转了科学计数法表示再判断是不是相等，这才是正确的想法，写出来代码也基本和晴神柳婼一样，
//（并不是说一样就好，只是在应付考试这个角度上学着套路化地解决问题效率较高，当然希望写出有独特思路的代码，但总要先模仿）
//不要妄图一次找到最优解，先解了再说！怎么就是不能好好实践这个道理？
//#pragma warning(disable: 4996)
//#include <string>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int main(int argc, char* argv[]) {
//	int N;
//	string A, B;
//	ios::sync_with_stdio(false);
//	cin >> N >> A >> B;//0?
//	int flag = 1, Alen = A.size(), Blen = B.size();
//	for (int i = 0; i < N && i < min(A.size(), B.size()); i++) {
//		if (A[i] != B[i]) flag = 0;
//		if (A[i] == '.') { A.erase(A.begin() + i); Alen = i; }//每一位是char
//		if (B[i] == '.') { B.erase(B.begin() + i); Blen = i; }
//	}
//	string Ares = A.substr(0, min(N, int(A.size())));
//	string Bres = B.substr(0, min(N, int(B.size())));
//	if (Ares.size() < N) for (int i = 0; i < N - Ares.size(); i++) Ares += "0";
//	if (Bres.size() < N) for (int i = 0; i < N - Bres.size(); i++) Bres += "0";
//	if (flag) cout << "YES 0." << Ares << "*10^" << Alen;
//	else cout << "NO 0." << Ares << "*10^" << Alen << " 0." << Bres << "*10^" << Blen;
//	system("pause");
//	return 0;
//}