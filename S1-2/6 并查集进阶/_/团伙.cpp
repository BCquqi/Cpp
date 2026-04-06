#include<iostream>
using namespace std;

const int N = 1005;
int f[2 * N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void Union(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx != fy) f[fx] = fy;
}

int main() {
	int n,m,ans = 0;
	cin >> n >> m;
	for (int i = 1;i <= 2 * n;i++) f[i] = i;
	for (int i = 1;i <= m;i++) {
		char opt;
		int p,q;
		cin >> opt >> p >> q;
		if (opt == 'F') Union(p,q);
		else {Union(q + n,p); Union(p + n,q);}
	}
	for (int i = 1;i <= n;i++) ans += (f[i] == i);
	cout << ans << endl;
	return 0;
}