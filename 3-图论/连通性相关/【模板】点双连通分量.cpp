#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 5e5 + 5;

vector<int> G[N];
int dfn[N],low[N],idx = 0;
int stk[N],top = 0;
vector<vector<int>> dcc;

void tarjan(int u,int pa) {
    dfn[u] = low[u] = ++idx;
    stk[++top] = u;
    int child = 0;
    for (auto v : G[u]) {
        if (v == pa) continue;
        if (!dfn[v]) {
            child++;
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if (low[v] >= dfn[u]) {
                vector<int> now;
                int x;
                do {
                    x = stk[top--];
                    now.push_back(x);
                } while (x != v);
                now.push_back(u), dcc.push_back(now);
            }
        }
        else low[u] = min(low[u], dfn[v]);
    }
    if (pa == 0 && child == 0) dcc.push_back({u});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = 1;i <= n;i++)
        if (!dfn[i]) tarjan(i,0);
    cout << dcc.size() << endl;
    for (auto it : dcc) {
        cout << it.size();
        for (int u : it) cout << ' ' << u;
        cout << endl;
    }
    return 0;
}