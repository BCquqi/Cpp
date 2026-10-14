#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;
int s[N][N],lg[N],stmax[N][N][11],stmin[N][N][11];

int main() {
	int a,b,n,ans = 1e9;
	cin >> a >> b >> n;
	for (int i = 1;i <= a;i++)
		for (int j = 1;j <= b;j++) cin >> s[i][j];
	lg[1] = 0;
	for (int i = 2;i <= N;i++) lg[i] = lg[i / 2] + 1;
	for (int i = 1;i <= a;i++)
        for (int j = 1;j <= b;j++)
            stmax[i][j][0] = stmin[i][j][0] = s[i][j];
	for (int j = 1;j <= lg[min(a,b)];j++)
		for (int x = 1;x + (1 << j) - 1 <= a;x++)
			for (int y = 1;y + (1 << j) - 1 <= b;y++) {
				stmax[x][y][j] = max(max(stmax[x][y][j - 1],stmax[x + (1 << j - 1)][y][j - 1]),max(stmax[x][y + (1 << j - 1)][j - 1],stmax[x + (1 << j - 1)][y + (1 << j - 1)][j - 1]));
				stmin[x][y][j] = min(min(stmin[x][y][j - 1],stmin[x + (1 << j - 1)][y][j - 1]),min(stmin[x][y + (1 << j - 1)][j - 1],stmin[x + (1 << j - 1)][y + (1 << j - 1)][j - 1]));
			}
    for (int x = 1;x + n - 1 <= a;x++)
        for (int y = 1;y + n - 1 <= b;y++) {
            int k = lg[n];
            int maxn = max(max(stmax[x][y][k],stmax[x + n - (1 << k)][y][k]),max(stmax[x][y + n - (1 << k)][k],stmax[x + n - (1 << k)][y + n - (1 << k)][k]));
            int minn = min(min(stmin[x][y][k],stmin[x + n - (1 << k)][y][k]),min(stmin[x][y + n - (1 << k)][k],stmin[x + n - (1 << k)][y + n - (1 << k)][k]));
            ans = min(ans,maxn -  minn);
        }
    cout << ans << endl;
	return 0;
}