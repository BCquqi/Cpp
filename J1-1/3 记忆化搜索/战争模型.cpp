#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int a,b,q;
long long f[2005][2005];

long long dfs(int x,int y)
{
	if (x <= 0 && y <= 0) return 0;
	if (x <= 0) return -y;
	if (y <= 0) return x;
	if (f[x][y] != -1) return f[x][y];
	return f[x][y] = dfs(x - (y + b - 1) / b,y - (x + a - 1) / a);
}

int main(){
	memset(f,-1,sizeof f);
	cin >> a >> b >> q;
	for (int i = 1;i <= q;i++)
	{
		int x,y;
		cin >> x >> y;
		if (dfs(x,y) > 0) cout << "X " << dfs(x,y) << endl;
		else if (dfs(x,y) < 0) cout << "Y " << -dfs(x,y) << endl;
		else cout << "EVEN" << endl;
	}
	return 0;
}