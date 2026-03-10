#include<iostream>
#include<map>
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
	while (true) {
		int n,q;
		cin >> n;
		if (!n) break;
		cin >> q;
		for (int i = 1;i <= n;i++) cin >> a[i];
		while (q--) {
			int l,r,ans = 0;
			cin >> l >> r;
			map<int,int> mp;
			for (int i = l;i <= r;i++) mp[a[i]]++,ans = max(ans,mp[a[i]]);
			cout << ans << endl;
		}
	}
	return 0;
}