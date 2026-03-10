#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[100005],dp[100005];

int main(){
	string s;
	cin >> s;
	int n = s.size();
	s = '?' + s;
	for (int i = 1;i <= s.size();i++) a[i] = s[i] - 'a';
	int cnt = 0;
	for (int i = 1;i <= n;i++)
	{
		int pos = upper_bound(dp + 1,dp + cnt + 1,a[i]) - dp;
		dp[pos] = a[i];
		cnt = max(cnt,pos);
	}
	cout << n - cnt << endl;
	return 0;
}
