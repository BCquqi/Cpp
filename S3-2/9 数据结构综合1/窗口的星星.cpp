#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
#define lid id << 1
#define rid id << 1 | 1
using namespace std;

const int N = 2e4 + 5;
struct Node {int x,y1,y2,tag;};
vector<Node> line;
vector<int> Y;
struct seg_tree {int l,r,maxn,lazy;} tr[N << 2];

void pushup(int id) {tr[id].maxn = max(tr[lid].maxn,tr[rid].maxn);}

void pushdown(int id) {
    if (tr[id].lazy) {
        tr[lid].maxn += tr[id].lazy, tr[rid].maxn += tr[id].lazy;
        tr[lid].lazy += tr[id].lazy, tr[rid].lazy += tr[id].lazy;
        tr[id].lazy = 0;
    }
}

void build(int id,int l,int r) {
    tr[id].l = l, tr[id].r = r;
    tr[id].lazy = tr[id].maxn = 0;
    if (l == r) return ;
    int mid = (tr[id].l + tr[id].r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
    pushup(id);
}

void modify(int id,int l,int r,int tag) {
    if (l <= tr[id].l && tr[id].r <= r) {
        tr[id].maxn += tag;
        tr[id].lazy += tag;
        return ;
    }
    int mid = (tr[id].l + tr[id].r) >> 1;
    pushdown(id);
    if (l <= mid) modify(lid,l,r,tag);
    if (mid < r) modify(rid,l,r,tag);
    pushup(id);
}

int get(int x) {return lower_bound(Y.begin(),Y.end(),x) - Y.begin() + 1;};

void solve() {
    line.clear(), Y.clear();
    int n,W,H;
    cin >> n >> W >> H;
    for (int i = 1;i <= n;i++) {
        int x,y,l;
        cin >> x >> y >> l;
        line.push_back({x,y,y + H - 1,l}), 
        line.push_back({x + W,y,y + H - 1,-l});
        Y.push_back(y), Y.push_back(y + H - 1);
    }
    sort(Y.begin(),Y.end());Y.erase(unique(Y.begin(),Y.end()),Y.end());
    int m = Y.size();
    sort(line.begin(),line.end(),[](Node a,Node b) {return a.x != b.x ? a.x < b.x : a.tag < b.tag;});
    build(1,1,m);
    int ans = 0;
    for (int i = 0;i < line.size();i++) {
        if (i > 0) ans = max(ans,tr[1].maxn);
        int ql = get(line[i].y1), qr = get(line[i].y2);
        if (ql <= qr) modify(1,ql,qr,line[i].tag);
    }
    cout << ans << endl;
    return ;
}

signed main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}