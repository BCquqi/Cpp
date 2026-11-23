#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1e6 + 5;
int n;
int h[N],w[N],S[N],dp[N];
struct Line {int m,c; int calc(int x) {return m * x + c;}} tr[N << 2];

void init() {
    for (int i = 1;i < (N << 2);i++) tr[i].c = 4e18;
    return ;
}

void insert(Line nl,int idx,int l,int r) {
    int mid = (l + r) >> 1;
    Line &cur = tr[idx];
    if (nl.calc(mid) < cur.calc(mid)) swap(cur,nl);
    if (l == r) return ;
    if (nl.calc(l) < cur.calc(l)) insert(nl,idx << 1,l,mid);
    else insert(nl,idx << 1 | 1,mid + 1,r);
    return ;
}

void insert(Line nl) {insert(nl,1,0,N - 1);}

int query(int x,int idx,int l,int r) {
    int res = tr[idx].calc(x);
    if (l == r) return res;
    int mid = (l + r) >> 1;
    if (x <= mid) res = min(res,query(x,idx << 1,l,mid));
    else res = min(res,query(x,idx << 1 | 1,mid + 1,r));
    return res;
}

int query(int x) {return query(x,1,0,N - 1);}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> h[i];
    for (int i = 1;i <= n;i++) cin >> w[i];
    for (int i = 1;i <= n;i++) S[i] = S[i - 1] + w[i];
    init();
    for (int i = 1;i <= n;i++) dp[i] = 4e18;
    dp[1] = 0;
    insert(Line{-2 * h[1],dp[1] + h[1] * h[1] - S[1]});
    for (int i = 2;i <= n;i++) {
        int res = query(h[i]);
        dp[i] = h[i] * h[i] + S[i - 1] + res;
        insert(Line{-2 * h[i],dp[i] + h[i] * h[i] - S[i]});
    }
    cout << dp[n] << endl;
    return 0;
}