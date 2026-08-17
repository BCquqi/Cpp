#include<iostream>
#include<vector>
#include<cstring> 
using namespace std;

const int N = 55;
vector<int> G[N]; 
bool dp[N][N][35];
int dis[N][N];

int main() {
	int n,m;
	cin >> n >> m;
	memset(dis,0x3f,sizeof dis);
	for (int i = 1;i <= m;i++) {
		int u,v;
		cin >> u >> v;
		G[u].push_back(v); 
		dp[u][v][0] = true, dis[u][v] = 1; 
	}
	for (int len = 1;len <= 31;len++)
		for (int k = 1;k <= n;k++)
			for (int i = 1;i <= n;i++)
				for (int j = 1;j <= n;j++)
					if (dp[i][k][len - 1] && dp[k][j][len - 1])
						dp[i][j][len] = true, dis[i][j] = 1;
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	cout << dis[1][n] << endl;
	return 0;
}
