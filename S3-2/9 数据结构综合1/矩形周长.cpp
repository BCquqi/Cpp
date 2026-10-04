#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
#define lid id << 1
#define rid id << 1 | 1
using namespace std;

const int N = 2e4 + 5;
struct Node {int x,y1,y2,tag;};
vector<Node> line;
struct seg_tree {int l,r,len,cnt,num; bool l_cover,r_cover;} tr[N << 2];

void pushup(int id) {
    if (tr[id].cnt) tr[id].len = tr[id].r - tr[id].l + 1, tr[id].num = 1,tr[id].l_cover = tr[id].r_cover = 1;
    else if (tr[id].l == tr[id].r) tr[id].len = tr[id].num = 0, tr[id].l_cover = tr[id].r_cover = 0;
    else {
        tr[id].len = tr[lid].len + tr[rid].len, 
        tr[id].num = tr[lid].num + tr[rid].num;
        if (tr[lid].r_cover && tr[rid].l_cover) tr[id].num--;
        tr[id].l_cover = tr[lid].l_cover, tr[id].r_cover = tr[rid].r_cover;
    }
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

signed main() {
    int n,m = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 10001, y1 += 10001, x2 += 10001, y2 += 10001;
        m = max(m,y2);
        line.push_back({x1,y1,y2,1}), 
        line.push_back({x2,y1,y2,-1});
    }
    sort(line.begin(),line.end(),[](Node a,Node b) {return a.x != b.x ? a.x < b.x : a.tag > b.tag;});
    build(1,1,m);
    int ans = 0,last = 0;
    for (int i = 0;i < line.size();i++) {
        if (i > 0)
            ans += 2 * tr[1].num * (line[i].x - line[i - 1].x);
        int ql = line[i].y1, qr = line[i].y2 - 1;
        if (ql <= qr) modify(1,ql,qr,line[i].tag);
        ans += abs(tr[1].len - last), last = tr[1].len;
    }
    cout << ans << endl;
    return 0;
}