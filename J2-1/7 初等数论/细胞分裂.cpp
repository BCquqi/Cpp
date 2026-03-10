#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e4 + 5,M = 3e4 + 5;
int s[N],p[M],k[M];

int main(){
	int n,m1,m2,cur = 0,ans = 1e9;
	cin >> n >> m1 >> m2;
	for (int i = 1;i <= n;i++) cin >> s[i];
	for (int i = 2;i * i <= m1;i++)
	{
		if (m1 % i == 0) p[++cur] = i;
		while (m1 % i == 0) k[cur]++,m1 /= i;
	}
	if (m1 > 1) p[++cur] = m1,k[cur] = 1;
	for (int i = 1;i <= n;i++)
	{
		int t = 0;
		for (int j = 1;j <= cur;j++)
		{
			if (s[i] % p[j] != 0) {t = 1e9; break;}
			int y = 0;
			while (s[i] % p[j] == 0) y++,s[i] /= p[j];
			t = max(t,(k[j] * m2 + y - 1) / y);
		}
		ans = min(ans,t);
	}
	cout << (ans == 1e9 ? -1 : ans) << endl;
	return 0;
}