#include<algorithm>
#include<iostream>
#define lid id << 1
#define rid id << 1 | 1
using namespace std;

const int T = 31,N = 100010;
int n,t,m;
int laz[T][N << 2],sum[T][N << 2];

void pushup(int c,int id) {sum[c][id] = sum[c][lid] + sum[c][rid];}

void build(int c,int id,int l,int r) {
	laz[c][id] = -1;
	if (l == r) {
		sum[c][id] = (c == 1);
		return ;
	}
	int mid = (l + r) >> 1;
	build(c,lid,l,mid);
	build(c,rid,mid + 1,r);
	pushup(c,id);
}

void cover(int c,int id,int l,int r,int v) {
	sum[c][id] = (r - l + 1) * v;
	laz[c][id] = v;
}

void pushdown(int c,int id,int l,int r) {
	if (laz[c][id] == -1) return ;
	int mid = (l + r) >> 1;
	cover(c,lid,l,mid,laz[c][id]);
	cover(c,rid,mid + 1,r,laz[c][id]);
	laz[c][id] = -1;
}

void change(int c,int id,int l,int r,int ls,int rs,int v) {
	if (l > rs || r < ls) return ;
	if (ls <= l && r <= rs) {
		cover(c,id,l,r,v);
		return ;
	}
	pushdown(c,id,l,r);
	int mid = (l + r) >> 1;
	if (ls <= mid) change(c,lid,l,mid,ls,rs,v);
	if (rs > mid) change(c,rid,mid + 1,r,ls,rs,v);
	pushup(c,id);
}

int ask(int c,int id,int l,int r,int ls,int rs) {
	if (l > rs || r < ls) return 0;
	if (ls <= l && r <= rs) return sum[c][id];
	pushdown(c,id,l,r);
	int mid = (l + r) >> 1;
	return ask(c,lid,l,mid,ls,rs) + ask(c,rid,mid + 1,r,ls,rs);
}

int main() {
	cin >> n >> t >> m;
	for (int c = 1;c <= t;c++) build(c,1,1,n);
	while (m--) {
		char op;
		int l,r;
		cin >> op >> l >> r;
		if (l > r) swap(l,r);
		if (op == 'C') {
			int c;
			cin >> c;
			for (int i = 1;i <= t;i++)
				change(i,1,1,n,l,r,i == c);
		}
		else {
			int ans = 0;
			for (int i = 1;i <= t;i++)
				if (ask(i,1,1,n,l,r)) ans++;
			cout << ans << endl;
		}
	}
	return 0;
}