#pragma warning(disable: 4996)
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string toSci(string str, int valid) {//д����ȥ��ʱ��Ӳ��ͷƤд
	string sci;
	//Ҫȥ��ǰ��0
	while (str[0] == '0')
		str.erase(str.begin());
	if (str[0] == '.' || str.size() <= 0) {//�ȴ�����������Ϊ������
		int nonZero = -1, zhishu = 0;
		if (str.size() <= 0) sci = "0";
		else {
			for (int i = 2; i < str.size(); i++)//�ҵ���һ����Ϊ���λ��
				if (str[i] != '0') {
					nonZero = i;
					break;
				}
			if (nonZero == -1) sci = "0";//�Ҳ����ͻ���0
			else {//����0�������������
				zhishu = -(nonZero - 1);//�ҵ��˾ͻ������Ч�������ַ���
				sci = str.substr(nonZero);//Ӧ�ÿ��Խ�ȡ�����
			}
		}
		int siz = sci.size();
		if (sci.size() > valid)
			sci = sci.substr(0, valid);
		else if (sci.size() < valid)//λ�������ʹ�0
			for (int i = 0; i < valid - siz; i++)//ǧ��Ҫ��һ����̬�����ŵ����������sci.size()
				sci += "0";
		else;
		sci = "0." + sci + "*10^" + to_string(zhishu);//sci����Чλ��zhishu��ָ��
	}
	else {//�ٴ���һ��ʼ�����������
		int slen = str.size();
		for (int i = 0; i < slen; i++)//�ҵ�.������Ҳ�����ûС��λ
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
	int N;//���ȣ�����˵��Чλ��
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
//���Ե�4ʵ����̫���ˣ���0001.1������ʽ...��ע�������Ż�����Ϊ��ѧ��������ģ�塣
//ԭ���õ��������������ֻ��������ĿSampleInput SampleOutput���ֱ����������ˣ�û�кúö��⣬
//һ����ͨ����ֻ��0 1 2 5���Ե���ȷ��3 4 6���Ե��Ǵ�ģ��ҹ�����0.xxx�����ݡ�
//֮�������ת�˿�ѧ��������ʾ���ж��ǲ�����ȣ��������ȷ���뷨��д��������Ҳ�������������Sһ����
//��������˵һ���ͺã�ֻ����Ӧ����������Ƕ���ѧ����·���ؽ������Ч�ʽϸߣ���Ȼϣ��д���ж���˼·�Ĵ��룬����Ҫ��ģ�£�
//��Ҫ��ͼһ���ҵ����Ž⣬�Ƚ�����˵����ô���ǲ��ܺú�ʵ���������
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
//		if (A[i] == '.') { A.erase(A.begin() + i); Alen = i; }//ÿһλ��char
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