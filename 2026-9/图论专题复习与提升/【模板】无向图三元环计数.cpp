#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5,M = 2e5 + 5;
int u[M],v[M],deg[N],last[N];
vector<int> G[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        cin >> u[i] >> v[i];
        deg[u[i]]++, deg[v[i]]++;
    }
    for (int i = 1;i <= m;i++)
        if (deg[u[i]] > deg[v[i]]) G[v[i]].push_back(u[i]);
        else if (deg[u[i]] == deg[v[i]] && u[i] > v[i]) G[v[i]].push_back(u[i]);
        else G[u[i]].push_back(v[i]);
    long long ans = 0;
    for (int i = 1;i <= n;i++) {
        for (auto j : G[i]) last[j] = i;
        for (auto j : G[i])
            for (auto k : G[j])
                if (last[k] == i) ans++;
    }
    cout << ans << endl;
    return 0;
}