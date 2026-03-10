#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
int dis[N],vis[N],cnt[N],n,k;

bool spfa() {
    memset(dis,-0x3f,sizeof dis);
    queue<int> q;
    for (int i = 1;i <= n;i++) {
        dis[i] = vis[i] = cnt[i] = 1;
        q.push(i);
    }
    int tot = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        if (++tot > 1e7) return true;
        for (auto [v,w] : G[u]) {
            if (dis[v] >= dis[u] + w) continue;
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
    cin >> n >> k;
    for (int i = 1;i <= k;i++) {
        int x,a,b;
        cin >> x >> a >> b;
        switch (x) {
            case 1 : {G[a].push_back({b,0}); G[b].push_back({a,0}); break;}
            case 2 : {G[a].push_back({b,1}); break;}
            case 3 : {G[b].push_back({a,0}); break;}
            case 4 : {G[b].push_back({a,1}); break;}
            case 5 : {G[a].push_back({b,0}); break;}
        }
    }
    if (spfa()) cout << -1 << endl;
    else {
        long long ans = 0;
        for (int i = 1;i <= n;i++) ans += dis[i];
        cout << ans << endl;
    }
    return 0;
}