#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
bool a[N];
int s[2],b[2],deg[N];

void solve() {
    memset(s,0,sizeof s);
    memset(b,0,sizeof b);
    memset(deg,0,sizeof deg);
    memset(a,0,sizeof a);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        s[a[i]]++;
    }
    for (int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        if (a[u] != a[v]) deg[u]++, deg[v]++;
    }
    for (int i = 1;i <= n;i++)
        if (deg[i] != 0) b[a[i]]++;
    for (int i = 1;i <= n;i++) {
        if (deg[i] > 0) cout << s[a[i]] - 1 + 2 * s[!a[i]] - deg[i] << ' ';
        else cout << s[a[i]] - 1 + 3 * s[!a[i]] - b[!a[i]] << ' ';
    }
    cout << endl;
    return ;
}

int main() {
    freopen("traffic.in","r",stdin);
    freopen("traffic.out","w",stdout);
    int c,T;
    cin >> c >> T;
    while (T--) solve();
    return 0;
}