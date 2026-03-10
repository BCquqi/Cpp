#include<iostream>
#include<cstring>
using namespace std;

const int N = 1005;
int l[N],r[N],p[N],num[N];
long long sum = 0,ans = 1e18;
bool vis[N];

void dfs(int root,int depth) {
    sum += 1ll * depth * num[root];
    vis[root] = 1;
    if (p[root] && !vis[p[root]]) dfs(p[root],depth + 1);
    if (l[root] && !vis[l[root]]) dfs(l[root],depth + 1);
    if (r[root] && !vis[r[root]]) dfs(r[root],depth + 1);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> num[i] >> l[i] >> r[i];
        p[l[i]] = p[r[i]] = i;
    }
    for (int i = 1;i <= n;i++) {
        memset(vis,0,sizeof vis);
        sum = 0;
        dfs(i,0);
        ans = min(sum,ans);
    }
    cout << ans << endl;
    return 0;
}