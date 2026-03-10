#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
int vis[N];

void dfs(int u,int st) {
	if (vis[u] != 0) return ;
	vis[u] = st;
    for (auto v : G[u]) 
        if (!vis[v]) dfs(v,st);
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        G[v].push_back(u);
    }
    for (int i = n;i >= 1;i--) dfs(i,i);
    for (int i = 1;i <= n;i++) cout << vis[i] << ' ';
    cout << endl;
    return 0;
}