#include<iostream>
#include<cstring>
#include<algorithm>
#define lid id * 2
#define rid id * 2 + 1
#define int long long
using namespace std;

const int N = 1e5 + 5; 
int q,m;

struct seg_tree {int l,r,val;} tr[N << 2];

// build 函数: 全部初始值设成 1 为乘法做准备 
void build(int id,int l,int r) {
    tr[id].l = l,tr[id].r = r,tr[id].val = 1;
    if (l == r) return ;
    int mid = (l + r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
}

// change: 直接赋值 
void change(int id,int l,int r,int k) {
    if (l <= tr[id].l && tr[id].r <= r) {
    	tr[id].val = k;
        return ;
    }
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) change(lid,l,r,k);
    else if (l > mid) change(rid,l,r,k);
    else change(lid,l,mid,k), change(rid,mid + 1,r,k);
    tr[id].val = (tr[lid].val * tr[rid].val) % m;
}

// query: 求全段的乘法 
int query(int id,int l,int r) {
    if (tr[id].l == l && tr[id].r == r) return tr[id].val % m;
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) return query(lid,l,r);
    else if (l > mid) return query(rid,l,r);
    else return (query(lid,l,mid) * query(rid,mid + 1,r)) % m;
}

void solve() {
	memset(tr,0,sizeof tr); 
	cin >> q >> m;
	build(1,1,q);
	for (int i = 1;i <= q;i++) {
		int op,x;
		cin >> op >> x;
		if (op == 1) change(1,i,i,x);
		else change(1,x,x,1);
		cout << query(1,1,i) << endl;
	}
	return ;
}

signed main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
