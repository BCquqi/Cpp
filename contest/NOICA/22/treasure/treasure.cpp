#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

const int N = 2e5 + 5;
long long a[N],b[N],in[N];
bool vis[N];
int tmp[N],len = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) {
        cin >> b[i];
        if (b[i] == i) b[i] = 0;
        if (b[i]) in[b[i]]++;
    }
    queue<int> q;
    for (int i = 1;i <= n;i++)
        if (!in[i]) q.push(i);
    long long ans = 0;
    while (!q.empty()) {
        int u = q.front(), v = b[u]; q.pop();
        ans += a[u];
        if (a[u] > 0 && v) a[v] += a[u];
        if (v && !--in[v]) q.push(v);
    }
    for (int i = 1;i <= n;i++) {
        if (!in[i] || vis[i]) continue;
        len = 0;
        int u = i;
        while (!vis[u]) vis[u] = true, u = b[u], tmp[++len] = u;
        long long sum = 0;
        for (int j = 1;j <= len;j++) sum += a[tmp[j]];
        if (sum >= 0) {
            long long cur = 0;
            for (int j = 1;j <= len;j++)
                cur += 1ll * (len - j + 1) * a[tmp[j]];
            long long maxn = cur;
            for (int j = 2;j <= len;j++)
                cur = cur - 1ll * len * a[tmp[j - 1]] + sum, maxn = max(maxn,cur);
            ans += maxn;
        } else {
            int maxn = 1;
            for (int j = 2;j <= len;j++)
                if (a[tmp[j]] > a[tmp[maxn]]) maxn = j;
            if (a[tmp[maxn]] < 0) {
                ans += sum + a[tmp[maxn]];
                continue;
            }
            stack<int> st;
            for (int j = 0;j < len;j++)
                if (a[tmp[(maxn - 1 + j) % len + 1]] > 0)
                    st.push(tmp[(maxn - 1 + j) % len + 1]);
            while (!st.empty()) {
                int x = st.top(),y = b[x]; st.pop();
                if (a[x] <= 0) continue;
                ans += a[x], a[y] += a[x], a[x] = 0;
                if (a[y] > 0) st.push(y);
            }
            for (int j = 1;j <= len;j++)
                if (a[tmp[j]]) ans += a[tmp[j]];
        }
    }
    cout << ans << '\n';
    return 0;
}