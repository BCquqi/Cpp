#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

const int N = 6e5 + 5;
int a[N],b[N];
struct Node {
	int a,b;
} c[N];
map<int,int> mp;

int main() {
	cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6];
	int n,ans = 1e9;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> b[i];
	int cur = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= 6;j++)
			c[++cur] = {b[i] - a[j],i};
	sort(c + 1,c + n * 6 + 1,[](Node x,Node y){return x.a < y.a;});
	int cnt = 0;
	for (int l = 1,r = 1;r <= 6 * n;r++) {
		if (++mp[c[r].b] == 1) cnt++;
		while (cnt == n && mp[c[l].b] > 0) {
			ans = min(ans,c[r].a - c[l].a);
			if (--mp[c[l].b] == 0) cnt--;
			l++;
		}
	}
	cout << ans << endl;
	return 0;
}