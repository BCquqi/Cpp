#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int c[N],f[N],n,p;

struct Node {int s,e,l;} a[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);};

void Union(int x,int y) {
	int fx = find(x),fy = find(y);
	if (fx != fy) f[fx] = fy;
}

int kruskal() {
	for (int i = 1;i <= n;i++) f[i] = i;
	int ans = 0;
	for (int i = 1;i <= p;i++) {
		int fx = find(a[i].s),fy = find(a[i].e);
		if (fx == fy) continue;
		Union(fx,fy);
		ans += a[i].l;
	}
	return ans;
}

int main() {
	int minn = 1e9;
	cin >> n >> p;
	for (int i = 1;i <= n;i++) {
		cin >> c[i];
		minn = min(minn,c[i]);
	}
	for (int i = 1;i <= p;i++) {
		cin >> a[i].s >> a[i].e >> a[i].l;
		a[i].l = c[a[i].s] + c[a[i].e] + 2 * a[i].l;
	}
	sort(a + 1,a + p + 1,[](Node x,Node y) {return x.l < y.l;});
	cout << kruskal() + minn << endl;
	return 0;
}