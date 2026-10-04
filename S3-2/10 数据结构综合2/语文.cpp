#include<iostream>
#include<cstring>
#define lid id << 1
#define rid id << 1 | 1
using namespace std;

const int N = 1e5 + 5;
char c[N];
int cnt[30];

struct seg_tree {int l,r,lazy,sum[30];} tr[N << 2];

void pushup(int id) {
	for (int i = 0;i < 26;i++)
		tr[id].sum[i] = tr[lid].sum[i] + tr[rid].sum[i];
	return ;
}

void build(int id,int l,int r) {
	tr[id].l = l, tr[id].r = r, tr[id].lazy = -1;
    if (l == r) {
        tr[id].sum[c[l] - 'A'] = 1;
        return ;
    }
    int mid = (l + r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
    pushup(id);
}

void cover(int id,int l,int r,int k) {
    for (int c = 0;c < 26;c++) tr[id].sum[c] = 0;
    tr[id].sum[k] = r - l + 1;
    tr[id].lazy = k;
}

void pushdown(int id) {
	if (tr[id].lazy != -1) {
		cover(lid,tr[lid].l,tr[lid].r,tr[id].lazy), 
		cover(rid,tr[rid].l,tr[rid].r,tr[id].lazy);
		tr[id].lazy = -1;
	}
}

void update(int id,int l,int r,int k) {
    if (l <= tr[id].l && tr[id].r <= r) {
        cover(id,tr[id].l,tr[id].r,k);
        return ;
    }
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (l <= mid) update(lid,l,r,k);
    if (mid < r) update(rid,l,r,k);
    pushup(id);
}

int query(int id,int l,int r,int k) {
	if (l <= tr[id].l && tr[id].r <= r)
		return tr[id].sum[k];
	pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1,ans = 0;
    if (l <= mid) ans += query(lid,l,r,k);
    if (mid < r) ans += query(rid,l,r,k);
    return ans;
}

void query_all(int id,int l,int r) {
	if (l <= tr[id].l && tr[id].r <= r) {
		for (int i = 0;i < 26;i++)
			cnt[i] += tr[id].sum[i];
		return ;
	}
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (l <= mid) query_all(lid,l,r);
    if (mid < r) query_all(rid,l,r);
}

int main() {
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> c[i];
	build(1,1,n);
	while (m--) {
		int op;
		cin >> op;
		switch (op) {
			case 1 : {
				int x,y;
				char k;
				cin >> x >> y >> k;
				cout << query(1,x,y,k - 'A') << endl;
				break;
			}
			case 2 : {
				int x,y;
				char k;
				cin >> x >> y >> k;
				update(1,x,y,k - 'A');
				break;
			}
			case 3 : {
				int x,y;
				cin >> x >> y;
				memset(cnt,0,sizeof cnt);
				query_all(1,x,y);
				int cur = x;
				for (int c = 0;c < 26;c++) {
					if (cnt[c]) {
						update(1,cur,cur + cnt[c] - 1,c);
						cur += cnt[c];
					}
				}
				break;
			}
		}
	}
	return 0;
}