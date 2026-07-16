#include<iostream>
#define lid id * 2
#define rid id * 2 + 1
#define int long long
using namespace std;

const int N = 1e5 + 5;
int a[N];

struct seg_tree {int l,r,lazy,sum;} tr[N << 2];

void build(int id,int l,int r) {
	tr[id].l = l,tr[id].r = r;
	if (l == r) {
		tr[id].sum = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(lid,l,mid);
	build(rid,mid + 1,r);
	tr[id].sum = tr[lid].sum + tr[rid].sum;
}

void pushdown(int id) {
	if (tr[id].lazy && tr[id].l != tr[id].r) {
		tr[lid].lazy += tr[id].lazy;
		tr[rid].lazy += tr[id].lazy;
		tr[lid].sum += tr[id].lazy * (tr[lid].r - tr[lid].l + 1);
		tr[rid].sum += tr[id].lazy * (tr[rid].r - tr[rid].l + 1);
		tr[id].lazy = 0;
	}
}

void add(int id,int l,int r,int val) {
	if (l <= tr[id].l && tr[id].r <= r) {
		tr[id].lazy += val;
		tr[id].sum += val * (tr[id].r - tr[id].l + 1);
		return ;
	}
	pushdown(id);
	int mid = (tr[id].l + tr[id].r) >> 1ll;
	if (r <= mid) add(lid,l,r,val);
	else if (l > mid) add(rid,l,r,val);
	else add(lid,l,mid,val), add(rid,mid + 1,r,val);
	tr[id].sum = tr[lid].sum + tr[rid].sum;
}

int query(int id,int l,int r) {
	if (tr[id].l == l && tr[id].r == r) return tr[id].sum;
	pushdown(id);
	int mid = (tr[id].l + tr[id].r) >> 1;
	if (r <= mid) return query(lid,l,r);
	else if (l > mid) return query(rid,l,r);
	else return query(lid,l,mid) + query(rid,mid + 1,r);
}

signed main() {
    int ma
	return 0;
}