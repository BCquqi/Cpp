#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
struct Edge {int u,v,w;} e[2 * N];
vector<int> G[N];

int n,m,f[N],ans[N],forced[N],bad[N],blocked[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}
void merge(int x,int y) {f[find(x)] = find(y);}

int main() {
    freopen("revue.in","r",stdin);
    freopen("revue.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= m;i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    for (int b = 19;b >= 0;b--) {
        for (int i = 1;i <= n;i++) f[i] = i,forced[i] = bad[i] = blocked[i] = 0,G[i].clear();
        for (int i = 1;i <= m;i++)
            if ((e[i].w >> b) & 1) merge(e[i].u,e[i].v);
        for (int i = 1;i <= m;i++)
            if ((e[i].w >> b) & 1) forced[find(e[i].u)] = 1;
        for (int i = 1;i <= n;i++) forced[i] = forced[find(i)];
        for (int i = 1;i <= m;i++) {
            if (!((e[i].w >> b) & 1)) {
                if (forced[e[i].u]) bad[e[i].v] = 1;
                if (forced[e[i].v]) bad[e[i].u] = 1;
                G[e[i].u].push_back(e[i].v), G[e[i].v].push_back(e[i].u);
            }
        }
        for (int i = 1;i <= n;i++) {
            if (forced[i]) ans[i] |= (1 << b);
            else if (!bad[i] && !blocked[i]) {
                ans[i] |= (1 << b);
                for (auto v : G[i]) blocked[v] = 1;
            }
        }
    }
    for (int i = 1;i <= n;i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}