#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int b[N];
map<int,int> mp;

int main() {
	int n,k,ans = 0;
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> b[i];
	int cnt = 0;
	for (int l = 1,r = 1;r <= n;r++) {
		if (++mp[b[r]] == 1) cnt++;
		while (cnt > k + 1 && mp[b[l]] > 0) {
			if (--mp[b[l]] == 0) cnt--;
			l++;
		}
		ans = max(ans,mp[b[r]]);
	}
	cout << ans << endl;
	return 0;
}