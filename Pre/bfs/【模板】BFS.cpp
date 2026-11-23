#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int dis[];
bool vis[];

void bfs()
{
	queue<int> q;
	q.push();
	dis[] = 0;
	vis[] = true;
	while (q.size())
	{
		int now = q.front();
		q.pop();
		if (now == ) return ;
		int nxt = ;
		if (nxt && !vis[nxt])
		{
			dis[nxt] = dis[now] + 1;
			vis[nxt] = true;
			q.push(nxt);
		}
	}
}
