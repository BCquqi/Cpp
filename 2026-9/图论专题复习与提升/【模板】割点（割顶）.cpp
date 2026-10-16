#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
int dfn[N],low[N],idx = 0,ans = 0;
bool isans[N];

void tarjan(int u,int fa) {
    dfn[u] = low[u] = ++idx;
    bool flag = false;
    int child = 0;
    for (auto v : G[u]) {
        if (!dfn[v]) {
            child++;
            tarjan(v, u);
            low[u] = min(low[u],low[v]);
            if (low[v] >= dfn[u]) flag = true;
        }
        else if (v != fa) low[u] = min(low[u],dfn[v]);
    }
    if (fa == 0 && child < 2) flag = false;
    if (flag) ans++, isans[u] = true;
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int i = 1;i <= n;i++)
        if (!dfn[i]) tarjan(i,0); 
    cout << ans << endl;
    for (int i = 1;i <= n;i++)
        if (isans[i]) cout << i << ' ';
    cout << endl;
    return 0;
}