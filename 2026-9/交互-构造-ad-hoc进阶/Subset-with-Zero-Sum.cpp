#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1e6 + 5;
int to[N],ans[N],cur = 0;
bool vis[N];

void solve() {
    memset(vis,0,sizeof vis);
    memset(ans,0,sizeof ans);
    cur = 0;
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int x;
        cin >> x;
        to[i] = i - x;
    }
    int u;
    for (u = 1;!vis[u];u = to[u]) vis[u] = true;
    int tmp = u;
    ans[++cur] = u, u = to[u];
    while (u != tmp) ans[++cur] = u, u = to[u];
    cout << cur << endl;
    for (int i = 1;i <= cur;i++)
        cout << ans[i] << ' ';
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}