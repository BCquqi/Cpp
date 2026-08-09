#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

const int N = 105;
string w;
int r,c,ans = 0;
char a[N][N];
int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};
struct Node {int x,y,id,d; bool flag;} ;
// id 代表处理到 w 的哪一位，d 表示正在行进的方向(初始为-1)，flag 记录是否转向过
queue<Node> q;


int main() {
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    cin >> w >> r >> c;
    for (int i = 1;i <= r;i++)
        for (int j = 1;j <= c;j++) {
            cin >> a[i][j];
            if (a[i][j] == w[0]) q.push({i,j,0,-1,false});
        }
    while (!q.empty()) {
        Node p = q.front(); q.pop();
        if (p.id == w.size() - 1) {
            ans++;
            continue;
        }
        for (int i = 0;i < 8;i++) {
            int nx = p.x + dx[i],ny = p.y + dy[i];
            if (nx < 1 || nx > r || ny < 1 || ny > c) continue;
            if (a[nx][ny] != w[p.id + 1]) continue;
            if (p.d != -1 && p.d != i && !p.flag) {
                if (dx[i] * dx[p.d] == -dy[i] * dy[p.d]) // 判断垂直的定理
                    q.push({nx,ny,p.id + 1,i,true});
            } // 必须打括号
            else if (p.d == i) q.push({nx,ny,p.id + 1,p.d,p.flag});
            else if (p.d == -1) q.push({nx,ny,p.id + 1,i,false});
        }
    }
    cout << ans << endl;
    return 0;
}