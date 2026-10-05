#include<iostream>
using namespace std;

bool flag[10];

int main() {
	string s;
	cin >> s;
	s = ' ' + s;
	if (s[1] == '1') {cout << "No" << endl; return 0;}
	flag[1] |= (s[7] - '0');
	flag[2] |= (s[4] - '0');
	flag[3] |= (s[2] - '0') | (s[8] - '0');
	flag[4] |= (s[1] - '0') | (s[5] - '0');
	flag[5] |= (s[3] - '0') | (s[9] - '0');
	flag[6] |= (s[6] - '0');
	flag[7] |= (s[10] - '0');
	for (int i = 1;i < 7;i++)
		for (int j = i + 1;j <= 7;j++)
			for (int k = i + 1;k < j;k++)
				if (flag[i] && flag[j] && (!flag[k])) {
					cout << "Yes" << endl;
					return 0;
				}
	cout << "No" << endl;
	return 0;
}