#include<iostream>
#define int long long
#define lid id * 2
#define rid id * 2 + 1
using namespace std;

const int N = 1e5 + 5,mod = 1e9 + 7;
struct Matrix {
    int a[2][2];
    Matrix() {a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;};
    Matrix(long long e,long long f,long long g,long long h) 
    {a[0][0] = e, a[0][1] = f, a[1][0] = g, a[1][1] = h;}
    void init() {a[0][0] = a[1][1] = 1, a[0][1] = a[1][0] = 0;}
};
int n,m,a[N];
Matrix p(1,1,1,0),sum[N << 2],lazy[N << 2];

Matrix operator + (const Matrix &x,const Matrix &y) {
	Matrix ret;
	for (int i = 0;i <= 1;i++)
		for (int j = 0;j <= 1;j++)
			ret.a[i][j] = (x.a[i][j] + y.a[i][j]) % mod;
	return ret;
}

Matrix operator * (const Matrix &x,const Matrix &y) {
    Matrix ret;
    for (int i = 0;i <= 1;i++)
        for (int j = 0;j <= 1;j++)
            for (int k = 0;k <= 1;k++)
                ret.a[i][j] = (ret.a[i][j] + x.a[i][k] * y.a[k][j] % mod + mod) % mod;
    return ret;
}

Matrix qpow(Matrix a,int b) {
    Matrix ret;
    ret.init();
    while (b) {
        if (b & 1) ret = ret * a;
        a = a * a;
        b >>= 1;
    }
    return ret;
}

void pushup(int id) {sum[id] = sum[lid] + sum[rid];}

void pushdown(int id) {
    sum[lid] = lazy[id] * sum[lid];
	lazy[lid] = lazy[id] * lazy[lid];
    sum[rid] = lazy[id] * sum[rid];
	lazy[rid] = lazy[id] * lazy[rid];
	lazy[id].init();
}

void build(int id,int l,int r) {
	lazy[id].init();
	if (l == r) {
		sum[id].a[0][0] = 1, sum[id].a[1][0] = 0;
        Matrix qp = qpow(p,a[l] - 1);
        sum[id] = qp * sum[id];
		return ;
	}
	int mid = (l + r) >> 1;
	build(lid,l,mid);
	build(rid,mid + 1,r);
	pushup(id);
    return ;
}

void add(int id,int l,int r,int L,int R,Matrix x) {
	if (L <= l && r <= R) {
		sum[id] = x * sum[id], lazy[id] = x * lazy[id];
	    return ;
	}
	pushdown(id);
	int mid = (l + r) >> 1;
	if (L <= mid) add(lid,l,mid,L,R,x);
	if (R > mid) add(rid,mid + 1,r,L,R,x);
	pushup(id);
    return ;
}

Matrix query(int id, int l, int r, int L, int R) {
	if (L <= l && r <= R) return sum[id];
	pushdown(id);
	int mid = (l + r) >> 1;
	Matrix ret;
	if (L <= mid) ret = query(lid,l,mid,L,R);
	if (R > mid) ret = ret + query(rid,mid + 1,r,L,R);
	return ret;
}

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l,r,x;
            cin >> l >> r >> x;
            add(1,1,n,l,r,qpow(p,x));
        } else {
            int l,r;
            cin >> l >> r;
            Matrix ans = query(1,1,n,l,r);
            cout << ans.a[0][0] << endl;
        }
    }
    return 0;
}