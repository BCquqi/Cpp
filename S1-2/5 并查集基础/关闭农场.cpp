#include<iostream>
#include<vector>
using namespace std;

const int N = 2e5 + 5;
vector<int> G[N];
int a[N],f[N];
bool vis[N],ans[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void Union(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx != fy) f[fx] = fy;
}

int main() {
    int n,m,cnt = 0;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
    }
    for (int i = 1;i <= n;i++) {cin >> a[i]; f[i] = i;}
    for (int i = n;i >= 1;i--) {
        int u = a[i];
        vis[u] = true;
        for (auto v : G[u]) {
            if (!vis[v]) continue;
            if (find(u) != find(v)) {cnt++; Union(u,v);}
        }
        if (cnt == n - i) ans[i] = true;
    }
    for (int i = 1;i <= n;i++) cout << (ans[i] ? "YES" : "NO") << endl;
    return 0;
}