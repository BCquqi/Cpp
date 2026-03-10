#include<iostream>
#include<queue>
using namespace std;

int d,k,cnt = 0;
int dis[100005];
bool vis[100005];

void bfs()
{
	queue<int> q;
	for (int i = 1;i <= 9;i++) q.push(i);
	while (q.size())
	{
		int now = q.front();
		q.pop();
		cnt++;
		if (cnt == k)
		{
			cout << now << endl;
			return ;
		}
		for (int i = 0;i <= 9;i++)
		{
			if (abs(now % 10 - i) > d) continue;
			int nxt = now * 10 + i;
			q.push(nxt);
		}
	}
}

int main()
{
	cin >> d >> k;
	bfs();
	
	return 0;
}
