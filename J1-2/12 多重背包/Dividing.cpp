#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int v[20005];
bool dp[2][100005];

void solve()
{
	memset(dp,false,sizeof dp);
	int cur = 0,sum = 0;
	for (int i = 1;i <= 6;i++)
	{
		int z,tmp = 1;
		cin >> z;
		sum += z * i;
		while (z >= tmp)
		{
			v[++cur] = i * tmp;
			z -= tmp;
			tmp *= 2;
		}
		if (z > 0) v[++cur] = i * z;
	}
	dp[0][0] = true;
	if (sum % 2)
	{
		cout << "Can't be divided." << endl;
		return ;
	}
	for (int i = 1;i <= cur;i++)
		for (int j = 0;j <= sum / 2;j++)
		{
			dp[i & 1][j] |= dp[i - 1 & 1][j];
			if (j >= v[i]) dp[i & 1][j] |= dp[i - 1 & 1][j - v[i]];
		}
	if (dp[cur & 1][sum / 2]) cout << "Can be divided." << endl;
	else cout << "Can't be divided." << endl;
	return ;
}

int main(){
	int T;
	cin >> T;
	for (int i = 1;i <= T;i++)
	{
		printf("Collection #%d:\n",i);
		solve();
	}
	return 0;
}
