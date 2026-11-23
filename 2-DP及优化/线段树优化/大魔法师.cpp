#include<iostream>
#define int long long
#define lid id << 1
#define rid id << 1 | 1
using namespace std;

const int N = 2.5e5 + 5,mod = 998244353;
int n,m;
int a[N],b[N],c[N];

struct Matrix {
    int a[4][4];

    Matrix() {
        for (int i = 0;i < 4;i++)
            for (int j = 0;j < 4;j++) a[i][j] = 0;
    }

    static Matrix init() {
        Matrix ret;
        for (int i = 0;i < 4;i++) ret.a[i][i] = 1;
        return ret;
    }

    Matrix operator * (Matrix y) const {
        Matrix r;
        for (int i = 0;i < 4;i++)
            for (int j = 0;j < 4;j++)
                for (int k = 0;k < 4;k++)
                    r.a[i][j] = (r.a[i][j] + a[i][k] * y.a[k][j]) % mod;
        return r;
    }

    static Matrix modify(int op,int v) {
        Matrix m = init();
        if (op == 1) m.a[0][1] = 1;
        else if (op == 2) m.a[1][2] = 1;
        else if (op == 3) m.a[2][0] = 1;
        else if (op == 4) m.a[0][3] = v;
        else if (op == 5) m.a[1][1] = v;
        else if (op == 6) m.a[2][2] = 0, m.a[2][3] = v;
        return m;
    }
};

struct seg_tree {int l,r; int suma,sumb,sumc; Matrix lazy;} tr[N << 2];

inline void apply(int id,int len,Matrix M) {
    int sa = tr[id].suma,sb = tr[id].sumb,sc = tr[id].sumc;
    tr[id].suma = (1LL * M.a[0][0] * sa + 1LL * M.a[0][1] * sb + 1LL * M.a[0][2] * sc + 1LL * M.a[0][3] * len) % mod;
    tr[id].sumb = (1LL * M.a[1][0] * sa + 1LL * M.a[1][1] * sb + 1LL * M.a[1][2] * sc + 1LL * M.a[1][3] * len) % mod;
    tr[id].sumc = (1LL * M.a[2][0] * sa + 1LL * M.a[2][1] * sb + 1LL * M.a[2][2] * sc + 1LL * M.a[2][3] * len) % mod;
    tr[id].lazy = M * tr[id].lazy;
}

inline void pushup(int id) {
    tr[id].suma = (tr[lid].suma + tr[rid].suma) % mod, 
    tr[id].sumb = (tr[lid].sumb + tr[rid].sumb) % mod, 
    tr[id].sumc = (tr[lid].sumc + tr[rid].sumc) % mod;
}

inline void pushdown(int id) {
    if (tr[id].l == tr[id].r) return ;
    int mid = (tr[id].l + tr[id].r) >> 1;
    apply(lid,mid - tr[id].l + 1,tr[id].lazy);
    apply(rid,tr[id].r - mid,tr[id].lazy);
    tr[id].lazy = Matrix::init();
}

void build(int id,int l,int r) {
    tr[id].l = l, tr[id].r = r;
    tr[id].lazy = Matrix::init();
    if (l == r) {
        tr[id].suma = a[l], 
        tr[id].sumb = b[l], 
        tr[id].sumc = c[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
    pushup(id);
}

void update(int id,int l,int r,int ql,int qr,Matrix M) {
    if (ql <= l && r <= qr) {
        apply(id,r - l + 1,M);
        return ;
    }
    pushdown(id);
    int mid = (l + r) >> 1;
    if (ql <= mid) update(lid,l,mid,ql,qr,M);
    if (qr > mid) update(rid,mid + 1,r,ql,qr,M);
    pushup(id);
}

struct Result {int suma,sumb,sumc;};

Result query(int id,int l,int r,int ql,int qr) {
    if (ql <= l && r <= qr)
        return {tr[id].suma,tr[id].sumb,tr[id].sumc};
    pushdown(id);
    int mid = (l + r) >> 1;
    Result res = {0,0,0};
    if (ql <= mid) {
        Result tmp = query(lid,l,mid,ql,qr);
        res.suma = (res.suma + tmp.suma) % mod, 
        res.sumb = (res.sumb + tmp.sumb) % mod, 
        res.sumc = (res.sumc + tmp.sumc) % mod;
    }
    if (qr > mid) {
        Result tmp = query(rid,mid + 1,r,ql,qr);
        res.suma = (res.suma + tmp.suma) % mod, 
        res.sumb = (res.sumb + tmp.sumb) % mod, 
        res.sumc = (res.sumc + tmp.sumc) % mod;
    }
    return res;
}

void solve() {
    int op,l,r,v = 0;
    cin >> op >> l >> r;
    if (op >= 4 && op <= 6) cin >> v;
    if (op == 7) {
        Result res = query(1,1,n,l,r);
        cout << res.suma << ' ' << res.sumb << ' ' << res.sumc << endl;
    } else {
        Matrix M = Matrix::modify(op,v);
        update(1,1,n,l,r,M);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i] >> b[i] >> c[i];
    build(1,1,n);
    cin >> m;
    while (m--) solve();
    return 0;
}