#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n,a[15];
bool flag,vis[15];

bool check()
{
	for (int i = 1;i <= n;i++)
		for (int j = i + 1;j <= n;j++)
		{
			if (a[i] == a[j]) return false;
			if (abs(a[i] - a[j]) == abs(i - j)) return false;
		}
	return true;
}

void dfs(int step)
{
	if (flag) return ;
	if (step > n)
	{
		if (check())
		{
			for (int i = 1;i <= n;i++) cout << a[i] << ' ';
			flag = true;
		}
		return ;
	}
	for (int i = 1;i <= n;i++)
	{
		if (vis[i]) continue;
		a[step] = i;
		vis[i] = true;
		dfs(step + 1);
		vis[i] = false;
		a[step] = 0;
	}
}

int main(){
	cin >> n;
	dfs(1);
	cout << endl;
	return 0;
}