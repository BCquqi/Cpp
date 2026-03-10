#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 205;
int t[N],G[N][N];

int main() {
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> t[i];
	memset(G,0x3f,sizeof G);
	while (m--) {
		int i,j,w;
		cin >> i >> j >> w;
		i++,j++;
		G[i][j] = G[j][i] = min(G[i][j],w);
	}
	for (int i = 1;i <= n;i++) G[i][i] = 0;
	int q,k = 1;
	cin >> q;
	while (q--) {
		int x,y,day;
		cin >> x >> y >> day;
		x++,y++;
		if (t[x] > day || t[y] > day) {
			cout << -1 << endl;
			continue;
		}
		while (t[k] <= day && k <= n) {
			for (int i = 1;i <= n;i++)
				for (int j = 1;j <= n;j++)
					G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
			k++;
		}
		if (G[x][y] > 1e9) cout << -1 << endl;
		else cout << G[x][y] << endl;
	}
	return 0;
}