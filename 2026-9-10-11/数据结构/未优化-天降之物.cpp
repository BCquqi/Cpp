#include<iostream>
#include<cmath>
#include<set>
using namespace std;

const int N = 1e5 + 5,len = 250,maxnum = 405,INF = 1e9;
int n,m,num = 0;
int a[N];
int pos[N];

struct Block {
    int l,r;
    int id[N + 5],val[len + 5];
    int first[len + 5],last[len + 5];
    int dis[len + 5][len + 5];
} b[maxnum];

void init(bool rebuild,int bid,int x,int y) {
    for (int i = 1;i <= num;i++)
        b[i].l = (i - 1) * len + 1, b[i].r = min(i * len,n);
    if (rebuild) {
        for (int i = b[bid].l;i <= b[bid].r;i++) b[bid].id[a[i]] = 0;
        for (int i = b[bid].l;i <= b[bid].r;i++)
            if (a[i] == x) a[i] = y;
    }
    set<int> s;
    for (int j = b[bid].l;j <= b[bid].r;j++) s.insert(a[j]);
    int idx = 0;
    for (int x : s) b[bid].id[x] = ++idx, b[bid].val[idx] = x;
    for (int c = 1;c <= idx;c++) b[bid].first[c] = b[bid].last[c] = 0;
    for (int j = b[bid].l;j <= b[bid].r;j++) {
        int id = b[bid].id[a[j]];
        if (!b[bid].first[id]) b[bid].first[id] = j;
        b[bid].last[id] = j;
    }
    for (int i = 1;i <= idx;i++)
        for (int j = 1;j <= idx;j++)
            b[bid].dis[i][j] = INF;
    for (int j = b[bid].l;j < b[bid].r;j++) {
        int id1 = b[bid].id[a[j]];
        for (int k = j + 1;k <= b[bid].r;k++) {
            int id2 = b[bid].id[a[k]];
            if (id1 == id2) {
                b[bid].dis[id1][id2] = b[bid].dis[id2][id1] = INF;
                continue;
            }
            int d = k - j;
            if (d < b[bid].dis[id1][id2])
                b[bid].dis[id1][id2] = b[bid].dis[id2][id1] = d;
        }
    }
    return ;
}

inline void modify(int x,int y) {
    if (x == y) return ;
    for (int i = 1;i <= num;i++) {
        int idx = b[i].id[x],idy = b[i].id[y];
        if (idx == 0) continue;
        else if (idy == 0) {
            for (int j = b[i].l;j <= b[i].r;j++)
                if (a[j] == x) a[j] = y;
            b[i].id[x] = 0, b[i].id[y] = idx, b[i].val[idx] = y;
        }
        else init(1,i,x,y);
    }
}

inline int query(int x,int y) {
    if (x == y) {
        for (int i = 1;i <= num;i++)
            if (b[i].id[x]) return 0;
        return INF;
    }
    int ans = INF;
    for (int i = 1;i <= num;i++) {
        int idx = b[i].id[x],idy = b[i].id[y];
        if (idx == 0 || idy == 0) continue;
        ans = min(ans,b[i].dis[idx][idy]);
    }
    int lx = -INF, ly = -INF;
    for (int i = 1;i <= num;i++) {
        int idx = b[i].id[x],idy = b[i].id[y];
        if (idx && idy)
            ans = min(ans,b[i].first[idx] - ly), 
            ans = min(ans,b[i].first[idy] - lx);
        else if (idx)
            ans = min(ans,b[i].first[idx] - ly);
        else if (idy)
            ans = min(ans,b[i].first[idy] - lx);
        if (idx) lx = b[i].last[idx];
        if (idy) ly = b[i].last[idy];
    }
    return ans;
}

int main() {
    cin >> n >> m;
    num = (n + len - 1) / len;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= num;i++) init(0,i,0,0);
    int lastans = 0;
    while (m--) {
        int opt, x, y;
        cin >> opt >> x >> y;
        x ^= lastans, y ^= lastans;
        if (opt == 1) modify(x,y);
        else {
            int ans = query(x, y);
            if (ans == INF) {
                cout << "Ikaros\n";
                lastans = 0;
            } else {
                cout << ans << '\n';
                lastans = ans;
            }
        }
    }
    return 0;
}