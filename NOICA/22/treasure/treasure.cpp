#include<iostream>
#include<algorithm>
#include<queue>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int n,ans = -1e18;
int a[N],b[N],s[N],cnt[N],plan[N],cpy[N];
bool vis[N];

void dfs(int step) {
    if (step > n) {
        int res = 0;
        for (int i = 1;i <= n;i++) cpy[i] = a[i];
        for (int i = 1;i <= n;i++)
            res += cpy[plan[i]], cpy[b[plan[i]]] += cpy[plan[i]];
        ans = max(ans,res);
        return ;
    }
    for (int i = 1;i <= n;i++) {
        if (vis[i]) continue;
        plan[step] = i, vis[i] = true;
        dfs(step + 1);
        plan[step] = 0, vis[i] = false;
    }
}

signed main() {
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) cin >> b[i];
    if (n <= 8) {
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}