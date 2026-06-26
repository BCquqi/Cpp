#include <bits/stdc++.h>
using namespace std;
string S;
bool f[10];
int main() {
	cin >> S;
	if (S[0] == '1') {
		cout << "No";
		return 0;
	} 
	f[1] = (S[6] == '1');
	f[2] = (S[3] == '1');
	f[3] = (S[1] == '1') || (S[7] == '1');
	f[4] = (S[0] == '1') || (S[4] == '1');
	f[5] = (S[2] == '1') || (S[8] == '1');
	f[6] = (S[5] == '1');
	f[7] = (S[9] == '1');
	for (int i = 1; i <= 7; ++i)
		for (int j = i + 1; j <= 7; ++j)
			for (int k = j + 1; k <= 7; ++k)
				if (f[i] && !f[j] && f[k]) {
					cout << "Yes";
					return 0;
				}
	cout << "No";
	return 0;
}
