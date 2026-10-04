#include<iostream>
#include<vector>
#define lid id << 1
#define rid id << 1 | 1
#define int long long
using namespace std;

const int N = 1e5 + 5;
int a[N],in[N],out[N],idx = 0,b[2 * N],v[2 * N];
vector<int> G[N];

struct seg_tree {int l,r,lazy,sum,sumb;} tr[N << 3];

void pushup(int id) {
    tr[id].sum = tr[lid].sum + tr[rid].sum, 
    tr[id].sumb = tr[lid].sumb + tr[rid].sumb;
    return ;
}

void build(int id,int l,int r) {
    tr[id].l = l,tr[id].r = r;
    if (l == r) {
        tr[id].sum = b[l] * v[l], tr[id].sumb = b[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
    pushup(id);
}

void pushdown(int id) {
	if (tr[id].lazy && tr[id].l != tr[id].r) {
		tr[lid].lazy += tr[id].lazy, 
		tr[rid].lazy += tr[id].lazy, 
		tr[lid].sum += tr[id].lazy * tr[lid].sumb, 
		tr[rid].sum += tr[id].lazy * tr[rid].sumb, 
		tr[id].lazy = 0;
	}
}

void add(int id,int l,int r,int val) {
	if (l <= tr[id].l && tr[id].r <= r) {
        tr[id].lazy += val;
        tr[id].sum += val * tr[id].sumb;
        return ;
    }
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) add(lid,l,r,val);
    else if (l > mid) add(rid,l,r,val);
    else add(lid,l,mid,val), add(rid,mid + 1,r,val);
    pushup(id);
}

int query(int id,int l,int r) {
	if (l <= tr[id].l && tr[id].r <= r) return tr[id].sum;
	pushdown(id);
	int mid = (tr[id].l + tr[id].r) >> 1;
	if (r <= mid) return query(lid,l,r);
    else if (l > mid) return query(rid,l,r);
    else return query(lid,l,mid) + query(rid,mid + 1,r);
}

void dfs(int u,int pa) {
    in[u] = ++idx, b[in[u]] = 1, v[in[u]] = a[u];
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
    }
    out[u] = ++idx, b[out[u]] = -1, v[out[u]] = a[u];
    return ;
}

signed main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i < n;i++) {
        int from,to;
        cin >> from >> to;
        G[from].push_back(to), G[to].push_back(from);
    }
    dfs(1,0);
    build(1,1,2 * n);
    while (m--) {
        int op;
        cin >> op;
        switch (op) {
            case 1 : {
                int x,a;
                cin >> x >> a;
                add(1,in[x],in[x],a), add(1,out[x],out[x],a);
                break;
            }
            case 2 : {
                int x,a;
                cin >> x >> a;
                add(1,in[x],out[x],a);
                break;
            }
            case 3 : {
                int x;
                cin >> x;
                cout << query(1,1,in[x]) << endl;
                break;
            }
        }
    }
    return 0;
}