#include<iostream>
#include<cstring>
using namespace std;

const int N = 205;
struct Edge {int v,w;};
int dp[N][N];

int main() {
	int n,m;
	cin >> n >> m;
	memset(dp,0x3f,sizeof dp);
	for (int i = 1;i <= m;i++) {
		int a,b,c;
		cin >> a >> b >> c;
		dp[a][b] = min(dp[a][b],c);
	}
	for (int i = 1;i <= n;i++) dp[i][i] = 0;
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++)
			cout << (dp[i][j] == 0x3f3f3f3f ? -1 : dp[i][j]) << ' ';
		cout << endl;
	}
	return 0;
}