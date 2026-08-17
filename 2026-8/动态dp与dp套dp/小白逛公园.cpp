#include<iostream>
#include<algorithm>
#define int long long
#define lid id * 2
#define rid id * 2 + 1
using namespace std;

const int N = 5e5 + 5;
struct Segment_Tree {int sum,max,mxl,mxr;} tr[N << 2];
int n,m,a[N],cur = 0;

void pushup(int id) {
    if (tr[lid].mxr < 0 && tr[rid].mxl < 0)
        tr[id].max = max(tr[lid].mxr,tr[rid].mxl);
    else
        tr[id].max = max(tr[lid].mxr,0ll) + max(tr[rid].mxl,0ll);
    tr[id].max = max(tr[id].max,max(tr[lid].max,tr[rid].max));
    tr[id].mxl = max(tr[lid].mxl,tr[lid].sum + tr[rid].mxl);
    tr[id].mxr = max(tr[rid].mxr,tr[rid].sum + tr[lid].mxr);
    tr[id].sum = tr[lid].sum + tr[rid].sum;
}

void build(int id,int l,int r) {
	if (l == r) {
        tr[id].sum = tr[id].mxl = tr[id].mxr = tr[id].max = a[++cur];
		return ;
	}
	int mid = (l + r) >> 1;
	build(lid,l,mid);
	build(rid,mid + 1,r);
	pushup(id);
    return ;
}

void modify(int id,int l,int r,int x,int y) {
	if (l == r) {
		tr[id].sum = tr[id].mxl = tr[id].mxr = tr[id].max = y;
	    return ;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) modify(lid,l,mid,x,y);
	else modify(rid,mid + 1,r,x,y);
	pushup(id);
    return ;
}

Segment_Tree query(int id, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tr[id];
	int mid = (l + r) >> 1;
    if (R <= mid) return query(lid,l,mid,L,R);
    if (L > mid) return query(rid,mid + 1,r,L,R);
    Segment_Tree res,left = query(lid, l, mid, L, R),right = query(rid, mid + 1, r, L, R);
    res.sum = left.sum + right.sum;
    res.mxl = max(left.mxl, left.sum + right.mxl);
    res.mxr = max(right.mxr, right.sum + left.mxr);
    res.max = max(max(left.max, right.max), left.mxr + right.mxl);
    return res;
}

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    while (m--) {
        int k;
        cin >> k;
        if (k == 1) {
            int a,b;
            cin >> a >> b;
            if (a > b) swap(a,b);
            cout << query(1,1,n,a,b).max << endl;
        } else {
            int p,s;
            cin >> p >> s;
            modify(1,1,n,p,s);
        }
    }
    return 0;
}