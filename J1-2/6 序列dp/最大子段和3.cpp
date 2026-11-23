#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int a[100005],dp[100005],pos,n,m;
// dp[i]是pos为i时的最大子段和

void solve()
{
	memset(dp,-0x3f,sizeof dp);
	int ret = -1e9;
	for (int i = pos;i <= n;i++)
		dp[i] = max(dp[i - 1] + a[i],a[i]),ret = max(ret,dp[i]);
	cout << ret << endl;
	return ;
}

int main(){
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= m;i++)
	{
		cin >> pos;
		solve();
	}
	return 0;
}
