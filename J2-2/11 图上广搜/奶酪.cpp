#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e3 + 5;
struct Node {
    int x,y,z;
} a[N];

vector<int> G[N];
bool vis[N];
int n,h,r;

bool check(Node x,Node y) {
    int dis = sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y) + (x.z - y.z) * (x.z - y.z));
    if (dis <= 2 * r) return true;
    return false;
}

void bfs() {
    queue<int> q;
    memset(vis,0,sizeof vis);
    q.push(0);
    vis[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : G[u]) {
            if (vis[v]) continue;
            q.push(v);
            vis[v] = true;
        }
    }
}

void solve() {
    for (int i = 1;i <= N;i++) G[i].clear();
    cin >> n >> h >> r;
    for (int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y >> a[i].z;
    for (int i = 1;i <= n;i++) {
        if (a[i].z - r <= 0) G[0].push_back(i);
        if (a[i].z + r >= h) G[n + 1].push_back(i);
        for (int j = i + 1;j <= n;j++)
            if (check(a[i],a[j])) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
    }
    for (auto u : G[0]) bfs();
    cout << (vis[n + 1] ? "Yes" : "No") << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}