#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;

const int N = 2e6 + 5;
int n,m,v,d[N],a[N],lg[N],f[N][30];
struct Pair {
    int id,a,b;
    bool operator < (const Pair &p) const {return p.b > b || (p.b == b && (p.a > a || (p.a == a && p.id < id)));}
};
priority_queue<Pair> pq;

void build() {
    for (int i = 2;i <= n;i++) lg[i] = lg[i >> 1] + 1;
    for (int i = 1;i <= n;i++) f[i][0] = a[i] - 1ll * i * v;
    for (int j = 1;j <= lg[n];j++)
        for (int i = 1;i + (1 << j) - 1 <= n;i++)
            f[i][j] = max(f[i][j - 1],f[i + (1 << (j - 1))][j - 1]);
}

int query(int l,int r) {
    int k = lg[r - l + 1];
    return max(f[l][k],f[r - (1 << k) + 1][k]);
}

int main() {
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> v;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) {
        pq.push({i,a[i],a[i]});
        Pair p = pq.top();
        pq.pop();
        p.b += v;
        d[i] = p.b;
        pq.push(p);
    }
    build();
    long long res1 = 0,res2 = 0;
    while (m--) {
        int x,k;
        cin >> x >> k;
        if (x + k - 1 <= n) {
            long long ans = d[x - 1];
            if (k >= 2) ans = max(0ll,max(ans,query(x + 1,x + k - 1) + 1ll * x * v + 1));
            res1 ^= ans,res2 += ans;
        }
    }
    cout << res1 << ' ' << res2 << endl;
    return 0;
}