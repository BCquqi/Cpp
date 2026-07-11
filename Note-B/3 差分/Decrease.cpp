#include<iostream>
#define int long long
using namespace std;

const int N = 5e3 + 5;
int a[N][N],d[N][N];

signed main() {
	int n,m,k,ans = 0;
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++) {
		int x,y,z;
		cin >> x >> y >> z;
		a[x][y] = z;
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++) {
			d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
			a[i][j] += d[i][j];
			if (a[i][j]) {
				if (i + k - 1 > n || j + k - 1 > n) {
					cout << -1 << endl;
					return 0;
				}
				d[i][j] -= a[i][j];
				d[i + k][j] += a[i][j];
				d[i][j + k] += a[i][j];
				d[i + k][j + k] -= a[i][j];
				ans += abs(a[i][j]);
			}
		}
	cout << ans << endl;
	return 0;
}
