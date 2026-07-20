#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int a[N],f[N],n,m;

multiset<int> s[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void Union(int x,int y) {
    int fx = find(x),fy = find(y);
    if (s[fx].size() > s[fy].size()) swap(fx,fy);
    auto it = --s[fx].end();
    s[fx].insert(*it / 2);
    s[fx].erase(it);
    it = --s[fy].end();
    s[fy].insert(*it / 2);
    s[fy].erase(it);
    for (auto t : s[fx]) s[fy].insert(t);
    s[fx].clear();
    f[fx] = fy;
}

void solve() {
	for (int i = 1;i <= n;i++) cin >> a[i];
	cin >> m;
	for (int i = 1;i <= n;i++) {
		f[i] = i;
		s[i].insert(a[i]);
	}
	while (m--) {
		int x,y;
		cin >> x >> y;
		if (find(x) == find(y)) {
			cout << -1 << endl;
			continue;
		}
		Union(x,y);
		cout << *--s[find(y)].end() << endl;
	}
	return ;
}

int main() {
	while (cin >> n) solve();
	return 0;
}