#include<iostream>
#include<algorithm>
using namespace std;

const int N = 305;
struct Node {int u,v,w;} a[N * N + N];
int f[N],n,cur;

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);};

void Union(int x,int y) {
	int fx = find(x),fy = find(y);
	if (fx != fy) f[fx] = fy;
}

int kruskal() {
	for (int i = 1;i <= n;i++) f[i] = i;
	int ans = 0;
	for (int i = 1;i <= cur;i++) {
		int fx = find(a[i].u),fy = find(a[i].v);
		if (fx == fy) continue;
		Union(a[i].u,a[i].v);
		ans += a[i].w;
	}
	return ans;
}

int main() {
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int v;
		cin >> v;
		a[++cur] = {0,i,v};
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++) {
			int p;
			cin >> p;
			a[++cur] = {i,j,p};
		}
	sort(a + 1,a + cur + 1,[](Node x,Node y) {return x.w < y.w;});
	cout << kruskal() << endl;
	return 0;
}