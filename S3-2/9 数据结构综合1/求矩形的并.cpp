#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
#define lid id << 1
#define rid id << 1 | 1
using namespace std;

const int N = 2e5 + 5;
struct Node {int x,y1,y2,tag;};
vector<Node> line;
vector<int> y;
struct seg_tree {int l,r,len,cnt;} tr[N << 2];

void pushup(int id) {
    if (tr[id].cnt)
        tr[id].len = y[tr[id].r] - y[tr[id].l - 1];
    else if (tr[id].l == tr[id].r) tr[id].len = 0;
    else tr[id].len = tr[lid].len + tr[rid].len;
}

void build(int id,int l,int r) {
    tr[id].l = l, tr[id].r = r;
    if (l == r) return ;
    int mid = (tr[id].l + tr[id].r) >> 1;
    build(lid,l,mid);
    build(rid,mid + 1,r);
    pushup(id);
}

void modify(int id,int l,int r,int tag) {
    if (l <= tr[id].l && tr[id].r <= r) {
        tr[id].cnt += tag;
        pushup(id);
        return ;
    }
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (l <= mid) modify(lid,l,r,tag);
    if (mid < r) modify(rid,l,r,tag);
    pushup(id);
}

int get(int x) {return lower_bound(y.begin(),y.end(),x) - y.begin() + 1;};

signed main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        line.push_back({x1,y1,y2,1}), 
        line.push_back({x2,y1,y2,-1}), 
        y.push_back(y1), y.push_back(y2);
    }
    sort(y.begin(),y.end());
    y.erase(unique(y.begin(),y.end()),y.end());
    int m = y.size();
    sort(line.begin(),line.end(),[](Node a,Node b) {return a.x < b.x;});
    build(1,1,m - 1);
    int ans = 0;
    for (int i = 0;i < line.size();i++) {
        if (i > 0)
            ans += tr[1].len * (line[i].x - line[i - 1].x);
        int ql = get(line[i].y1), qr = get(line[i].y2) - 1;
        if (ql <= qr) modify(1,ql,qr,line[i].tag);
    }
    cout << ans << endl;
    return 0;
}