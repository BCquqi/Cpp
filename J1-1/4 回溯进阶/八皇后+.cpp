#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n,k,a[20],cnt;
bool flag,vis[20];

bool check(int x)
{
	for (int i = 1;i <= x;i++)
		for (int j = i + 1;j <= x;j++)
		{
			if (a[i] == a[j]) return false;
			if (abs(a[i] - a[j]) == abs(i - j)) return false;
		}
	return true;
}

void dfs(int step)
{
	if (cnt >= k) return ;
	if (step > n)
	{
		cnt++;
		for (int i = 1;i <= n;i++) cout << a[i] << ' ';
		cout << endl;
		return ;
	}
	for (int i = 1;i <= n;i++)
	{
		if (vis[i]) continue;
		a[step] = i;
		if (!check(step)) continue;
		vis[i] = true;
		dfs(step + 1);
		vis[i] = false;
		a[step] = 0;
	}
}

int main(){
	cin >> n >> k;
	dfs(1);
	return 0;
}