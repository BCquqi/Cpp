#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int N = 55;
int u[N],v[N],deg[N];

void solve() {
    int n;
    cin >> n;
    memset(deg,0,sizeof deg);
    for (int i = 1;i < n;i++) {
        cin >> u[i] >> v[i];
        deg[u[i]]++, deg[v[i]]++;
    }
    int ans = 0;
    for (int i = 1;i < n;i++)
        if (deg[u[i]] > 1 && deg[v[i]] > 1) ans++;
    if (ans & 1) cout << "wizard" << endl;
    else cout << "villager" << endl;
    return ;
}

int main() {
    freopen("forest.in","r",stdin);
    freopen("forest.out","w",stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}