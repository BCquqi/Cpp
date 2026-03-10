#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 1e5 + 5;

int n,a[N];
int dis[N],cnt[N];
int vis[N];

int mod = 1e9 + 7;

void bfs()
{
	queue<int> q;
	q.push(1);
	dis[1] = 0;
	vis[1] = true;
	cnt[1] = 1;
	while (q.size())
	{
		int now = q.front();
		q.pop();
		for (int i = 1;i <= a[now];i++)
		{
			int nxt = now + i;
			if (1 <= nxt && nxt <= n && !vis[nxt])
			{
				dis[nxt] = dis[now] + 1;
				vis[nxt] = true;
				cnt[nxt] = (cnt[nxt] + cnt[now]) % mod;
				q.push(nxt);
			}
			else if (1 <= nxt && nxt <= n && dis[now] + 1 == dis[nxt])
			{
				cnt[nxt] = (cnt[nxt] + cnt[now]) % mod;
			}
		}
	}
}

int main(){
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	bfs();
	cout << dis[n] << endl;
	cout << cnt[n] << endl;
    return 0;
}
