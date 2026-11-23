#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define lid id << 1
#define rid id << 1 | 1
using namespace std;

const int N = 2e4 + 5;
int d[N],c[N],s[N],w[N],l[N],r[N];
vector<int> del[N];
int f[N],g[N];

struct segment {int l,r,lazy,mn;} tr[N << 2];

void pushup(int id) {tr[id].mn = min(tr[lid].mn,tr[rid].mn);}
void pushdown(int id) {
    if (tr[id].lazy && tr[id].l != tr[id].r) {
        tr[lid].lazy += tr[id].lazy;
        tr[rid].lazy += tr[id].lazy;
        tr[lid].mn += tr[id].lazy;
        tr[rid].mn += tr[id].lazy;
        tr[id].lazy = 0;
    }
}
void build(int id,int l,int r) {
    tr[id].l = l, tr[id].r = r, tr[id].lazy = 0;
    if (l == r) {
        tr[id].mn = g[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lid,l,mid), build(rid,mid + 1,r);
    pushup(id);
}
void modify(int id,int l,int r,int val) {
    if (l <= tr[id].l && tr[id].r <= r) {
        tr[id].lazy += val, tr[id].mn += val;
        return ;
    }
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) modify(lid,l,r,val);
    else if (l > mid) modify(rid,l,r,val);
    else modify(lid,l,mid,val), modify(rid,mid + 1,r,val);
    pushup(id);
}
int query(int id,int l,int r) {
    if (l <= tr[id].l && tr[id].r <= r) return tr[id].mn;
    pushdown(id);
    int mid = (tr[id].l + tr[id].r) >> 1;
    if (r <= mid) return query(lid,l,r);
    else if (l > mid) return query(rid,l,r);
    else return min(query(lid,l,mid),query(rid,mid + 1,r));
}

int main() {
    int n,K;
    // range | base maxinum number
    cin >> n >> K;
    d[1] = 0;
    for (int i = 2;i <= n;i++) cin >> d[i]; // village position
    for (int i = 1;i <= n;i++) cin >> c[i]; // costs to build a base
    for (int i = 1;i <= n;i++) cin >> s[i]; // cover radius
    for (int i = 1;i <= n;i++) cin >> w[i]; // costs to give villages not covered
    d[n + 1] = 1e9, c[n + 1] = s[n + 1] = w[n + 1] = 0;
    for (int i = 1;i <= n + 1;i++)
        l[i] = lower_bound(d + 1,d + n + 1,d[i] - s[i]) - d, 
        r[i] = upper_bound(d + 1,d + n + 1,d[i] + s[i]) - d - 1, 
        del[r[i] + 1].push_back(i);
    memset(g,0x3f,sizeof g);
    g[0] = 0;
    for (int j = 1;j <= K + 1;j++) {
        build(1,0,n);
        for (int i = 1;i <= n + 1;i++) {
            for (int k : del[i])
                if (l[k] >= 1) modify(1,0,l[k] - 1,w[k]);
            f[i] = c[i] + query(1,0,i - 1);
        }
        for (int i = 0;i <= n + 1;i++) g[i] = f[i];
    }
    cout << f[n + 1] << endl;
    return 0;
}