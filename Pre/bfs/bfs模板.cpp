#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int dis[]; // 记录访问每一个元素的步数 
bool vis[]; // 记录元素是否被访问过 

void bfs()
{
	queue<int> q;
	q.push(/*起点*/);
	dis[/*起点*/] = 0;
	vis[/*起点*/] = true;
	while (q.size())
	{
		int now = q.front();
		q.pop();
		if (now == /*终点*/) return ;
		int nxt = /*now的某种变换*/;
		if (nxt /*在题目的某种范围内*/ && !vis[nxt])
		{
			dis[nxt] = dis[now] + 1;
			vis[nxt] = true;
			q.push(nxt);
		}
	}
}
