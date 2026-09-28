#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 4005;
vector<int> G[N];
int dis[N][N],far[N][N];

// 思路：预处理最短路，然后枚举 b c，找出 a d (分别距离 b c 最远点)，计算答案

void bfs(int s) {
    memset(dis[s],-1,sizeof(dis[s]));
    queue<int> q;
    q.push(s);
    dis[s][s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : G[u]) {
            if (dis[s][v] == -1) {
                dis[s][v] = dis[s][u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    freopen("tour.in","r",stdin);
    freopen("tour.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y), G[y].push_back(x);
    }
    for (int i = 1;i <= n;i++) bfs(i);
    // 找前三大最远点, 目的是防止比如选中 d 且确定 c a b 然而前两个是 a b 这种重复的
    for (int i = 1;i <= n;i++) {
        far[i][1] = far[i][2] = far[i][3] = -1;
        for (int j = 1;j <= n;j++) {
            if (i == j || dis[i][j] == -1) continue;
            if (far[i][1] == -1 || dis[i][j] > dis[i][far[i][1]])
                far[i][3] = far[i][2], far[i][2] = far[i][1], far[i][1] = j;
            else if (far[i][2] == -1 || dis[i][j] > dis[i][far[i][2]])
                far[i][3] = far[i][2], far[i][2] = j;
            else if (far[i][3] == -1 || dis[i][j] > dis[i][far[i][3]])
                far[i][3] = j;
        }
    }
    int ans = 0;
    for (int b = 1;b < n;b++)
        for (int c = b + 1;c <= n;c++) {
            for (int i = 1;i <= 3;i++) {
                int a = far[b][i];
                if (a == c || a == -1) continue;
                for (int j = 1;j <= 3;j++) {
                    int d = far[c][j];
                    if (d == b || d == a || d == -1) continue;
                    ans = max(ans,dis[a][b] + dis[b][c] + dis[c][d]);
                }
            }
        }
    cout << ans << endl;
    return 0;
}