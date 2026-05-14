#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 2e5 + 5;
int r[N],n;
long long s[N],k[N],dis[N];
bool vis[N];
vector<int> G[N],rG[N];

void spfa() {
    queue<int> q;
    for (int i = 1;i <= n;i++) {
        q.push(i);
        vis[i] = true,dis[i] = k[i];
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for (auto v : rG[u]) {
            long long t = s[v];
            for (auto w : G[v]) {
                t += dis[w];
                if (t >= dis[v]) break;
            }
            if (t >= dis[v]) continue;
            dis[v] = t;
            if (!vis[v]) q.push(v);
            vis[v] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int u = 1;u <= n;u++) {
        cin >> s[u] >> k[u] >> r[u];
        for (int j = 1;j <= r[u];j++) {
            int v;
            cin >> v;
            G[u].push_back(v); rG[v].push_back(u);
        }
    }
    spfa();
    cout << dis[1] << endl;
    return 0;
}