#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;

int k[205],dis[205];

struct Node{
	int x,d;
};

int main()
{
	int n,a,b;
	cin >> n >> a >> b;
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
	}
	memset(dis,-1,sizeof(dis));
	dis[a] = 0;
	queue<Node> q;
	q.push({a,0});
	while (!q.empty())
	{
		Node now = q.front();
		q.pop();
		int x = now.x;
		int y = x + k[x];
		if ((1 <= y && y <= n) && dis[y] == -1)
		{
			dis[y] = now.d + 1;
			q.push({y,now.d + 1});
		}
		y = x - k[x];
		if ((1 <= y && y <= n) && dis[y] == -1)
		{
			dis[y] = now.d + 1;
			q.push({y,now.d + 1});
		}
	}
	cout << dis[b] << endl;
	return 0;
}
