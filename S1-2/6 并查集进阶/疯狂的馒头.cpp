#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 5;
int c[N],f[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void Union(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx != fy) f[fx] = fy;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	int n,m,p,q;
	cin >> n >> m >> p >> q;
	for (int i = 1;i <= n + 1;i++) f[i] = i;
	for (int i = m;i >= 1;i--) {
		int a = (i * p + q) % n + 1,b = (i * q + p) % n + 1;
		if (a > b) swap(a,b);
		for (int j = find(a);j <= b;j = find(j)) {
			if (!c[j]) c[j] = i;
			f[j] = find(j + 1);
		}
	}
	for (int i = 1;i <= n;i++) cout << c[i] << '\n';
	return 0;
}