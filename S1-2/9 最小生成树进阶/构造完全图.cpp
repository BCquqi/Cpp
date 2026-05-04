#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
struct Node {int u,v,w;} a[N];
int f[N],n;
long long siz[N];

int find(int x) {return x == f[x] ? f[x] : f[x] = find(f[x]);}

void Union(int x,int y) {
	int fx = find(x),fy = find(y);
	if (fx != fy) f[fx] = fy,siz[fy] += siz[fx];
}

long long kruskal() {
	for (int i = 1;i <= n;i++) f[i] = i,siz[i] = 1;
	long long ans = 0;
	for (int i = 1;i < n;i++) {
		int fx = find(a[i].u),fy = find(a[i].v);
		if (fx == fy) continue;
		ans += 1ll * (a[i].w + 1) * siz[fx] * siz[fy] - 1;
		Union(fx,fy);
	}
	return ans;
}      

int main() {
	cin >> n;
	for (int i = 1;i < n;i++) cin >> a[i].u >> a[i].v >> a[i].w;
	sort(a + 1,a + n,[](Node x,Node y) {return x.w < y.w;});
	cout << kruskal() << endl;
	return 0;
}