#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n,a[N];
int pm[N],pv[N],pcnt;
int sm[N],sv[N],scnt;
struct Node {int l,r,v;};
vector<Node> ev[N];

struct FenwickTree {
    int n;
    static int tree[N];

    FenwickTree(int size) : n(size) {fill(tree + 1,tree + n + 1,0);}

    void add(int x,int val) {while (x <= n) tree[x] += val, x += x & -x;}

    int sum(int x) {
        int ret = 0;
        while (x) ret += tree[x], x -= x & -x;
        return ret;
    }
};
int FenwickTree::tree[N];

struct SegTree {
    struct SegNode {int l,r,mx,lazy;};
    static SegNode tr[N << 2];

    SegTree(int size) {build(1,1,size);}

    void build(int id,int l,int r) {
        tr[id] = {l,r,0,0};
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(id << 1,l,mid);
        build(id << 1 | 1,mid + 1,r);
    }

    void pushup(int id) {tr[id].mx = max(tr[id << 1].mx,tr[id << 1 | 1].mx);}

    void pushdown(int id) {
        if (!tr[id].lazy) return;
        int lz = tr[id].lazy;
        tr[id << 1].lazy += lz;
        tr[id << 1 | 1].lazy += lz;
        tr[id << 1].mx += lz;
        tr[id << 1 | 1].mx += lz;
        tr[id].lazy = 0;
    }

    void modify(int id,int l,int r,int val) {
        if (l <= tr[id].l && tr[id].r <= r) {
            tr[id].mx += val;
            tr[id].lazy += val;
            return;
        }
        pushdown(id);
        int mid = (tr[id].l + tr[id].r) >> 1;
        if (l <= mid) modify(id << 1,l,r,val);
        if (r > mid) modify(id << 1 | 1,l,r,val);
        pushup(id);
    }
};
SegTree::SegNode SegTree::tr[N << 2];

int cinv() {
    FenwickTree bit(n);
    int ret = 0;
    for (int i = n;i >= 1;i--)
        ret += bit.sum(a[i] - 1), bit.add(a[i],1);
    return ret;
}

void solve() {
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    int inv = cinv();
    if (inv == 0) {
        cout << 0 << endl;
        return ;
    }
    pcnt = 0;
    int mx = 0;
    for (int i = 1;i <= n;i++)
        if (a[i] > mx)
            ++pcnt, pm[pcnt] = i, pv[pcnt] = a[i], mx = a[i];
    scnt = 0;
    int mn = 1e18;
    for (int i = n;i >= 1;i--)
        if (a[i] < mn) ++scnt, sm[scnt] = i, sv[scnt] = a[i], mn = a[i];
    reverse(sm + 1,sm + scnt + 1);
    reverse(sv + 1,sv + scnt + 1);
    for (int i = 1;i <= pcnt + 1;i++) ev[i].clear();
    for (int i = 1;i <= n;i++) {
        int pu = lower_bound(pm + 1,pm + pcnt + 1,i) - pm - 1;
        int pl = upper_bound(pv + 1,pv + pcnt + 1,a[i]) - pv;
        int sl = upper_bound(sm + 1,sm + scnt + 1,i) - sm;
        int su = lower_bound(sv + 1,sv + scnt + 1,a[i]) - sv - 1;
        if (pl <= pu && sl <= su)
            ev[pl].push_back({sl,su,1}), 
            ev[pu + 1].push_back({sl,su,-1});
    }
    SegTree seg(scnt);
    int best = 0;
    for (int i = 1;i <= pcnt;i++) {
        for (auto [l,r,v] : ev[i]) seg.modify(1,l,r,v);
        best = max(best,seg.tr[1].mx);
    }
    cout << inv - 1 - 2 * best << endl;
    return ;
}

signed main() {
    freopen("light.in","r",stdin);
    freopen("light.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T,o;
    cin >> T >> o;
    while (T--) solve();
    return 0;
}