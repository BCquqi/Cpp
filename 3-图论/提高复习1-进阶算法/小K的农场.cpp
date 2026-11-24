#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 5e3 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
int dis[N],vis[N],cnt[N],n,m;

bool spfa() {
    memset(dis,0x3f,sizeof dis);
    queue<int> q;
    for (int i = 1;i <= n;i++) {
        vis[i] = cnt[i] = 1;
        dis[i] = 0;
        q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for (auto [v,w] : G[u]) {
            if (dis[v] <= dis[u] + w) continue;
            dis[v] = dis[u] + w;
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
                if (++cnt[v] >= n) return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int op,a,b,c;
        cin >> op;
        switch (op) {
            case 1 : {
                cin >> a >> b >> c;
                G[a].push_back({b,-c});
                break;
            } case 2 : {
                cin >> a >> b >> c;
                G[b].push_back({a,c});
                break;
            } case 3 : {
                cin >> a >> b;
                G[a].push_back({b,0}); G[b].push_back({a,0});
                break;
            }
        }
    }
    cout << (spfa() ? "No" : "Yes") << endl;
    return 0;
}