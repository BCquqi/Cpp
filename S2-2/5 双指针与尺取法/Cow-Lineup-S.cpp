#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

const int N = 5e4 + 5;
struct Node {
	int x,id;
} a[N];
map<int,int> mp;
map<int,bool> vis;

int main() {
	int n,ans = 1e9;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int x,id;
		cin >> x >> id;
		a[i] = {x,id};
		vis[id] = true;
	}
	int k = vis.size(),cnt = 0;
	sort(a + 1,a + n + 1,[](Node x,Node y) {return x.x < y.x;});
	for (int l = 1,r = 1;r <= n;r++) {
		if (++mp[a[r].id] == 1) cnt++;
		while (cnt == k && mp[a[l].id] > 1) mp[a[l].id]--,l++;
		if (cnt == k) ans = min(ans,a[r].x - a[l].x);
	}
	cout << ans << endl;
	return 0;
}