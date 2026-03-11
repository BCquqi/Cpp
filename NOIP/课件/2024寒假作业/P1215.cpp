#include<iostream>
#include<cstdio>
using namespace std;

int a,b,c;
int box[25];
bool vis[25][25][25];

void dfs(int x,int y,int z)
{
	if (vis[x][y][z]) return ;
	vis[x][y][z] = true;
	if (x == 0) box[z]++;
	int t;
	t = min(x,b - y);
	dfs(x - t,y + t,z);
	t = min(x,c - z);
	dfs(x - t,y,z + t);
	t = min(y,a - x);
	dfs(x + t,y - t,z);
	t = min(y,c - z);
	dfs(x,y - t,z + t);
	t = min(z,a - x);
	dfs(x + t,y,z - t);
	t = min(z,b - y);
	dfs(x,y + t,z - t);
}

int main() {
	cin >> a >> b >> c;
	dfs(0,0,c);
	for (int i = 0;i <= c;i++)
		if (box[i] != 0) cout << i << ' ';
	cout << endl;
    return 0;
}
