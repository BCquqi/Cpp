#include<iostream>
#include<cmath>
using namespace std;

int solve() {
	char c;
	int ans = 0,x,t;
	while (cin >> c) {
		if (c == 'D') {cin >> x; ans += x;}
		else if (c == 'K') {cin >> x; ans -= x;}
		else if (c == 'T') {
			cin >> t >> c;
			ans += t * solve();
		}
		else if (c == ']') return ans;
	}
	return ans;
}

int main() {
	cout << abs(solve()) << endl;
	return 0;
}