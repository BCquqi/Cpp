#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 105;
int dp1[N][N],dp[N][N],n,m,ans = 1e9;

void copy() {
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            dp[i][j] = dp1[i][j];
}

int main() {
	cin >> n >> m;
	memset(dp1,0x3f,sizeof dp1);
	for (int i = 1;i <= m;i++) {
		int x,y,w;
		cin >> x >> y >> w;
		dp1[x][y] = dp1[y][x] = min(dp1[x][y],w);
	}
	for (int i = 1;i <= n;i++) dp1[i][i] = 0;
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				dp1[i][j] = min(dp1[i][j],dp1[i][k] + dp1[k][j]);
	for (int u = 1;u <= n;u++)
		for (int v = u + 1;v <= n;v++) {
            copy();
			int tmp = dp[u][v];
			dp[u][v] = dp[v][u] = 0;
			for (int i = 1;i <= n;i++)
				for (int j = 1;j <= n;j++)
					dp[i][j] = min(dp[i][j],min(dp[i][u] + dp[v][j],dp[i][v] + dp[u][j]));
            int sum = 0;
            for (int i = 1;i <= n;i++)
                for (int j = i + 1;j <= n;j++)
                    sum += dp[i][j];
            ans = min(ans,sum);
			dp[u][v] = dp[v][u] = tmp;
		}
    cout << ans << endl;
	return 0;
}