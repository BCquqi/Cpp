#include<iostream>
using namespace std;

const int N = 2e5 + 5;
string s[N];

int main() {
	freopen("geminae.txt","r",stdin);
	int n;
	cin >> n;
	for (int i = 1;i <= 2 * n;i++) cin >> s[i];
	for (int i = 1;i <= n;i++)
		if (s[i] != s[i + n]) cout << "Different in line " << i << ", " << s[i] << ' ' << s[i + n] << endl;
	cout << "finish\n";
	return 0;
}
