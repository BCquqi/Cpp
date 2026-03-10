#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5005,M = 5005;
int a[N],b[N],c[N],d[N],dp1[2][M],dp2[2][M];

int main(){
	int l,f,w,n,m;
	cin >> l >> f >> w >> n;
	for (int i = 1;i <= n;i++) cin >> a[i] >> b[i];
	cin >> m;
	for (int i = 1;i <= m;i++) cin >> c[i] >> d[i];
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= w;j++)
		{
			dp1[i & 1][j] = dp1[i - 1 & 1][j];
			if (j >= b[i]) dp1[i & 1][j] = max(dp1[i & 1][j],dp1[i - 1 & 1][j - b[i]] + a[i]);
		}
	for (int i = 1;i <= m;i++)
		for (int j = 0;j <= w;j++)
		{
			dp2[i & 1][j] = dp2[i - 1 & 1][j];
			if (j >= d[i]) dp2[i & 1][j] = max(dp2[i & 1][j],dp2[i - 1 & 1][j - d[i]] + c[i]);
		}
	long long ans = 0;
	for (int j = 0;j <= w;j++)
		ans = max(ans,1ll * (l + dp1[n & 1][j]) * (f + dp2[m & 1][w - j]));
	cout << ans << endl;
	return 0;
}
