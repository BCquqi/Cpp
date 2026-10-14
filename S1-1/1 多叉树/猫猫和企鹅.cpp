#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
int n,d,ans = 0;

void dfs(int u,int pa,int step) {
    if (step > d) return ;
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u,step + 1);
        if (step + 1 <= d) ans++;
    }
}

int main() {
    cin >> n >> d;
    for (int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0,0);
    cout << ans << endl;
    return 0;
}