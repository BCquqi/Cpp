#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

map <string,bool>mp;
int dp[1005];

int main(){
	string s;
	int n;
	cin >> s >> n;
	for (int i = 1;i <= n;i++)
	{
		string x;
		cin >> x;
		mp[x] = true;
	}
	int len = s.size();
	s = '?' + s;
	memset(dp,0x3f,sizeof dp);
	dp[0] = 0;
	for (int i = 1;i <= len;i++)
	{
		string k = "";
		for (int j = i;j >= 1;j--)
		{
			k = s[j] + k;
			if (mp.count(k)) dp[i] = min(dp[i],dp[j - 1] + 1);
		}
	}
	cout << dp[len] << endl;
	return 0;
}
