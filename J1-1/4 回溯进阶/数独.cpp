#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[10][10];
bool r[10][10],c[10][10],g[10][10];

void dfs(int step)
{
	if (step > 80)
	{
		for (int i = 0;i <= 8;i++)
			for (int j = 0;j <= 8;j++)
			{
				cout << a[i][j] << " \n"[j == 8];
			}
		return ;
	}
	int x = step / 9,y = step % 9;
	int k = x / 3 * 3 + y / 3;
	if (a[x][y] != 0) dfs(step + 1);
	else 
	{
		for (int i = 1;i <= 9;i++)
		{
			if (!r[x][i] && !c[y][i] && !g[k][i])
			{
				a[x][y] = i;
				r[x][i] = true;
				c[y][i] = true;
				g[k][i] = true;
				dfs(step + 1);
				a[x][y] = 0;
				r[x][i] = false;
				c[y][i] = false;
				g[k][i] = false;
			}
		}
	}
}

int main(){
	for (int i = 0;i <= 8;i++)
		for (int j = 0;j <= 8;j++)
		{
			cin >> a[i][j];
			if (a[i][j] != 0)
			{
				r[i][a[i][j]] = true;
				c[j][a[i][j]] = true;
				g[i / 3 * 3 + j / 3][a[i][j]] = true;
			}
		}
	dfs(0);
	return 0;
}