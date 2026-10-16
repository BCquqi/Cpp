#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;

const int N = 1e5 + 5,M = 35;
int a[N],b[N],c[N],d[N],amax[N][M],amin[N][M],afmx[N][M],azmn[N][M],bmax[N][M],bmin[N][M],lg[N];

void init(int n,int st[][M],int a[],bool op) {
    for (int i = 1;i <= n;i++) st[i][0] = a[i];
    for (int j = 1;j <= 20;j++)
        for (int i = 1;i + (1 << j) - 1 <= n;i++) {
            if (op) st[i][j] = max(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
            else st[i][j] = min(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
        }
}

int query(int l,int r,int st[][M],bool op) {
    int k = lg[r - l + 1];
    return (op ? max(st[l][k],st[r - (1 << k) + 1][k]) : min(st[l][k],st[r - (1 << k) + 1][k]));
}

signed main() {
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,m,q;
    cin >> n >> m >> q;
    lg[0] = -1;
    for (int k = 1;k <= N - 5;k++) lg[k] = lg[k >> 1] + 1;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        c[i] = (a[i] >= 0 ? -1e18 : a[i]);
        d[i] = (a[i] < 0 ? 1e18 : a[i]);
    }
    for (int i = 1;i <= m;i++) cin >> b[i];
    init(n,amax,a,1); init(n,amin,a,0); init(n,afmx,c,1); init(n,azmn,d,0); init(m,bmax,b,1); init(m,bmin,b,0);
    while (q--) {
        int l1,r1,l2,r2,ans = -1e18;
        cin >> l1 >> r1 >> l2 >> r2;
        int a = query(l1,r1,amax,1),b = query(l1,r1,amin,0),c = query(l1,r1,afmx,1),d = query(l1,r1,azmn,0),e = query(l2,r2,bmax,1),f = query(l2,r2,bmin,0);
        ans = max(ans,a * (a >= 0 ? f : e));
        ans = max(ans,b * (b >= 0 ? f : e));
        if (c != -1e18) ans = max(ans,c * (c >= 0 ? f : e));
        if (d != 1e18) ans = max(ans,d * (d >= 0 ? f : e));
        cout << ans << endl;
    }
    return 0;
}
