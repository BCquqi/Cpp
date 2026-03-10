#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

string s[1000005],dp[100005],ans[100005];

int main()
{
	string tmp;
	cin >> tmp;
	tmp = '?' + tmp;
	int cur = 0;
	int len = tmp.size();
	for (int i = 1;i <= len;i++)
	{
		if (tmp[i] >= 'A' && tmp[i] <= 'Z')
			s[++cur] += tmp[i];
		else s[cur] += tmp[i];
	}
	int cnt = 0;
	for (int i = 1;i <= len;i++)
	{
		int pos = lower_bound(dp + 1,dp + cnt + 1,s[i]) - dp;
		dp[pos] = s[i];
		cnt = max(cnt,pos);
		ans[pos] = ans[pos - 1] + s[i];
	}
	cout << ans[cnt] << endl;
	return 0;
}
