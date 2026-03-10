#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

const int N = 10005;
int v[20 * N],c[20 * N],w[20 * N],cnt[20 * N],dp1[2][30005],dp2[2][30005];

int main(){
	int n,T;
	cin >> n >> T;
	for (int i = 1;i <= n;i++) cin >> v[i];
	int cur = 0;
	for (int i =  1;i <= n;i++)
	{
		int z,tmp = 1;
		cin >> z;
		while (z >= tmp)
		{
			w[++cur] = tmp * v[i];
			cnt[cur] = tmp;
			z -= tmp;
			tmp *= 2;
		}
		if (z > 0)
		{
			w[++cur] = z * v[i];
			cnt[cur] = z;
		}
	}
	memset(dp1,0x3f,sizeof dp1);
	memset(dp2,0x3f,sizeof dp2);
	dp1[0][0] = 0,dp2[0][0] = 0;
	for (int i = 1;i <= cur;i++)
		for (int j = 0;j <= 3e4;j++)
		{
			dp1[i & 1][j] = dp1[i - 1 & 1][j];
			if (j >= w[i]) dp1[i & 1][j] = min(dp1[i & 1][j],dp1[i - 1 & 1][j - w[i]] + cnt[i]);
		}
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= 3e4;j++)
		{
			dp2[i & 1][j] = dp2[i - 1 & 1][j];
			if (j >= v[i]) dp2[i & 1][j] = min(dp2[i & 1][j],dp2[i & 1][j - v[i]] + 1);
		}
	int ans = 1e9;
	for (int j = T;j <= 3e4;j++)
		ans = min(ans,dp1[cur & 1][j] + dp2[n & 1][j - T]);
	if (ans >= 1e6) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
