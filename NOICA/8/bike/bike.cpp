#include<iostream>
#define int long long
using namespace std;

int x,v,ans = 1e18;
long long s;

void dfs(int step,int mov,int dist) {
    if (dist > s) return ;
    if (dist == s && mov == 0) {
        ans = min(ans,step);
        return ;
    }
    if (mov > 0) dfs(step,mov - 1,dist + mov);
    dfs(step + 1,mov + v - 1,dist + mov + v);
}

void solve() {
    cin >> x >> v >> s;
    ans = 1e18;
    dfs(0,x,0);
    cout << (ans == (long long) 1e18 ? -1 : ans) << endl;
}

signed main() {
    freopen("bike.in","r",stdin);
    freopen("bike.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}