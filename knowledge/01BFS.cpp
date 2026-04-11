#include <iostream>
#include<queue>
#include<deque>
#include<cstring>
using namespace std ;

struct Node { int x , y ; };
int t ;
const int N = 1010 ;
int r , c ;
char mp[N][N] ;
int dis[N][N] ;
int dx[] = { 1 , -1, 0 , 0  } ;
int dy[] = { 0 , 0 , 1 , -1 } ;

void bfs()
{
	memset(dis , 0x3f , sizeof dis ) ;
	deque <Node> q ;
	q.push_front({1 , 1}) ;
	dis[1][1] = 0 ;
	while(!q.empty())
	{
		Node x = q.front() ;
		int tx = x.x ;
		int ty = x.y ;
		q.pop_front() ;
		if(tx == r && ty == c) return ;
		for(int i = 0 ; i <= 3 ; i++ )
		{
			int nx = x.x + dx[i] ;
			int ny = x.y + dy[i] ;
			if(nx < 1 || nx > r || ny < 1 || ny > c ) continue ;
			if(mp[tx][ty] == mp[nx][ny] && dis[nx][ny] > dis[tx][ty])
			{
				dis[nx][ny] = dis[tx][ty] ;
				q.push_front({nx , ny}) ;
			}
			if(mp[tx][ty] != mp[nx][ny] && dis[nx][ny] > dis[tx][ty] + 1)
			{
				dis[nx][ny] = dis[tx][ty] + 1 ;
				q.push_back({nx , ny}) ;
			}
		}
	}
}

void solve()
{
	cin >> r >> c ;
	for(int i = 1 ; i <= r ; i++ )
		for(int j = 1 ; j <= c ; j++ )
			cin >> mp[i][j] ;
	
	bfs() ;
	cout << dis[r][c] << endl ;
}

int main()
{
	cin >> t ;
	while(t--) solve() ;
	return 0 ;
}