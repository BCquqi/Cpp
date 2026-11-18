#include<iostream>
#include<algorithm>
#include<set>
#include<cstring>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n,k;
int a[N],b[N],tree[N],id[N],val[N],dp[N],nxt[N];
set<pair<long long,int>> p;
set<int> s;

int lowbit(int x) {return x & -x;}
void add(int x,int val,int lim) {while (x <= lim) tree[x] += val, x += lowbit(x);}
long long query(int x) {
    long long ans = 0;
    while (x > 0) ans += tree[x], x -= lowbit(x);
    return ans;
}

int calc(int a[]) {
    p.clear(), s.clear();
    for (int i = 1;i <= n;i++) {
        id[i] = i, val[i] = a[i];
        p.insert({a[i],i});
    }
    sort(val + 1,val + n + 1);
    sort(id + 1,id + n + 1,[&](int x,int y) {return a[x] != a[y] ? a[x] > a[y] : x > y;});
    int m = unique(val + 1,val + n + 1) - val - 1;
    memset(tree, 0, sizeof(tree[0]) * (m + 1));
    for (int i = 1;i <= n;i++) nxt[i] = 0;
    for (int i = 1;i <= n;i++) {
        int j = id[i];
        int l = a[j],r = a[j] + k;
        auto it = p.lower_bound({l,0});
        while (it != p.end() && it -> first == l)
            s.insert(it -> second), it = p.erase(it);
        auto it2 = s.upper_bound(j);
        while (it2 != s.end() && a[*it2] > r)
            it2 = s.erase(it2);
        if (it2 != s.end()) nxt[j] = *it2;
    }
    for (int i = n;i >= 1;i--) {
        if (nxt[i] == 0) dp[i] = 1;
        else {
            int j = nxt[i];
            int x = lower_bound(val + 1,val + m + 1,a[j]) - val;
            int y = lower_bound(val + 1,val + m + 1,a[i]) - val;
            int cnt = query(x - 1) - query(y - 1);
            dp[i] = dp[j] + cnt + 1;
        }
        int pos = lower_bound(val + 1,val + m + 1,a[i]) - val;
        add(pos,1,m);
    }
    int ret = 0;
    for (int i = 1;i <= n;i++) ret += dp[i];
    return ret;
}

void solve() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = -a[i];
    }
    int ans = calc(a) + calc(b) - n;
    sort(b + 1,b + n + 1);
    int same = 0,cnt = 0,last = b[1];
    for (int i = 1;i <= n;i++) {
        if (b[i] != last) cnt = 0,last = b[i];
        same += cnt, cnt++;
    }
    cout << ans - same << endl;
    return ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}