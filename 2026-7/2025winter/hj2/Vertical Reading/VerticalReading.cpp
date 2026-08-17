#include<iostream>
using namespace std;

int main() {
	string s,t;
	cin >> s >> t;
	int len = s.size();
	s = ' ' + s;
	for (int w = 1;w < len;w++)
		for (int c = 1;c <= w;c++) {
			string tmp = "";
			for (int i = 0;i * w + c <= len;i++)
				tmp += s[i * w + c];
			if (tmp == t) {cout << "Yes" << endl; return 0;}
		}
	cout << "No" << endl;
	return 0;
}