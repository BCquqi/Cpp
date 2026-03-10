#include<iostream>
using namespace std;

const int N = 3005;
int h[N],dp1[N],dp2[N],f[N],g[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> h[i];
	for (int i = 1;i <= n;i++)
		for (int j = 0;j < i;j++)
		{
			if (h[i] > h[j]) dp1[i] = max(dp1[i],dp1[j] + 1);
			f[i] = max(f[i - 1],dp1[i]);
		}
	for (int i = n;i >= 1;i--)
		for (int j = i + 1;j <= n + 1;j++)
		{
			if (h[i] > h[j]) dp2[i] = max(dp2[i],dp2[j] + 1);
			g[i] = max(g[i + 1],dp2[i]);
		}
	int ans = 0;
	for (int i = 1;i <= n;i++)
		ans = max(ans,dp1[i] + dp2[i] - 1),ans = max(ans,f[i - 1] + g[i + 1]);
	cout << n - ans << endl;
	return 0;
}