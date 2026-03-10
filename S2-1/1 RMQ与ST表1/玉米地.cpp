#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;
int a[N][N],lg[N],stmax[N][N][11],stmin[N][N][11];

int main() {
	int n,b,k;
	cin >> n >> b >> k;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++) cin >> a[i][j];
	lg[1] = 0;
	for (int i = 2;i <= n;i++) lg[i] = lg[i / 2] + 1;
	for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) {
            stmax[i][j][0] = a[i][j];
            stmin[i][j][0] = a[i][j];
        }
	for (int j = 1;j <= lg[n];j++)
		for (int x = 1;x + (1 << j) - 1 <= n;x++)
			for (int y = 1;y + (1 << j) - 1 <= n;y++) {
				stmax[x][y][j] = max(max(stmax[x][y][j - 1],stmax[x + (1 << j - 1)][y][j - 1]),max(stmax[x][y + (1 << j - 1)][j - 1],stmax[x + (1 << j - 1)][y + (1 << j - 1)][j - 1]));
				stmin[x][y][j] = min(min(stmin[x][y][j - 1],stmin[x + (1 << j - 1)][y][j - 1]),min(stmin[x][y + (1 << j - 1)][j - 1],stmin[x + (1 << j - 1)][y + (1 << j - 1)][j - 1]));
			}
	while (k--) {
		int x,y;
		cin >> x >> y;
		int K = lg[b];
		int maxn = max(max(stmax[x][y][K],stmax[x + b - (1 << K)][y][K]),max(stmax[x][y + b - (1 << K)][K],stmax[x + b - (1 << K)][y + b - (1 << K)][K]));
		int minn = min(min(stmin[x][y][K],stmin[x + b - (1 << K)][y][K]),min(stmin[x][y + b - (1 << K)][K],stmin[x + b - (1 << K)][y + b - (1 << K)][K]));
		cout << maxn - minn << endl;
	}
	return 0;
}