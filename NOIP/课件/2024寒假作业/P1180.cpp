#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

double l,v,m,c,d[60],p[60],minn = 2e9;
int n;

void dfs(int step,double gas,double cost)
{
	if (step > n + 1)
	{
		minn = min(minn,cost);
		return ;
	}
	double dis = d[step + 1] - d[step];
	if (dis / m > gas)
		dfs(step + 1,v - dis / m, cost + (v - gas) * p[step] + 20);
	else
	{
		if (gas >= v / 2)
			dfs(step + 1,gas - dis / m,cost);
		else
		{
			dfs(step + 1,v - dis / m, cost + (v - gas) * p[step] + 20);
			dfs(step + 1,gas - dis / m,cost);
		}
	}
}

int main() {
	cin >> l;
	cin >> v >> m >> c >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> d[i] >> p[i];
	}
	d[n + 1] = l;
	dfs(0,v,c);
	printf("%.1lf",minn);
    return 0;
}
