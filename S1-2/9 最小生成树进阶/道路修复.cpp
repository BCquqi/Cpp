#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 1e5 + 5;
struct Node {int u,v,w;} a[N];
int c[N],f[N],n,m,k,cur;

int find(int x) {return x == f[x] ? f[x] : f[x] = find(f[x]);}

void Union(int x,int y) {
	int fx = find(x),fy = find(y);
	if (fx != fy) f[fx] = fy;
}

long long kruskal() {
	for (int i = 1;i <= n + k;i++) f[i] = i;
	long long ans = 0;
	for (int i = 1;i <= cur;i++) {
		int fx = find(a[i].u),fy = find(a[i].v);
		if (fx == fy) continue;
		ans += a[i].w;
		Union(a[i].u,a[i].v);
	}
	return ans;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++) cin >> a[i].u >> a[i].v >> a[i].w;
	cur = m;
	for (int i = 1;i <= k;i++) {
		cin >> c[i + n];
		for (int j = 1;j <= n;j++) {
			int x;
			cin >> x;
			a[++cur] = {n + i,j,x};
		}
	}
	sort(a + 1,a + cur + 1,[](Node x,Node y) {return x.w < y.w;});
	cout << kruskal() << endl;
	return 0;
}