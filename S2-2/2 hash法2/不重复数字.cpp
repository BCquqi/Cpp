#include<unordered_map>
#include<iostream>
using namespace std;

unordered_map<int,bool> mp;

int main() {
	int T;
	cin >> T;
	while (T--) {
		mp.clear();
		int n;
		cin >> n;
		for (int i = 1;i <= n;i++) {
			int x;
			cin >> x;
			if (!mp[x]) {cout << x << ' '; mp[x] = true;}
		}
		cout << endl;
	}
	return 0;
}