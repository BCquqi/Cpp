#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 3005;
int x[N],s[N],pre[N],cur[N];

inline int w(int l,int r) {
    int m = (l + r) >> 1;
    return x[m] * (m - l) - (s[m - 1] - s[l - 1]) + (s[r] - s[m]) - x[m] * (r - m);
}

void solve(int l,int r,int optl,int optr) {
    if (l > r) return ;
    int mid = (l + r) >> 1, best = optl;
    cur[mid] = 1e18;
    for (int j = optl;j <= min(optr, mid - 1);j++) {
        int v = pre[j] + w(j + 1, mid);
        if (v < cur[mid]) cur[mid] = v, best = j;
    }
    solve(l,mid - 1,optl,best);
    solve(mid + 1,r,best, optr);
    return ;
}

signed main() {
    int v,p;
    cin >> v >> p;
    for (int i = 1;i <= v;i++) cin >> x[i];
    sort(x + 1,x + v + 1);
    for (int i = 1;i <= v;i++) s[i] = s[i - 1] + x[i];
    for (int i = 1;i <= v;i++) pre[i] = 1e18;
    pre[0] = 0;
    for (int k = 1;k <= p;k++) {
        for (int i = 0;i <= v;i++) cur[i] = 1e18;
        solve(k,v,k - 1,v - 1);
        for (int i = 0;i <= v;i++) pre[i] = cur[i];
    }
    cout << pre[v] << endl;
    return 0;
}