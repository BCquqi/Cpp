#include<iostream>
#include<cstring>
using namespace std;

const int N = 3005;
int f[N];
struct Circle {int x,y,r;} a[N];

bool check1(int x1,int y1,int r,int x2,int y2) {return 1ll * (x2 - x1) * (x2 - x1) + 1ll * (y2 - y1) * (y2 - y1) == 1ll * r * r;}

bool check2(int x1,int y1,int r1,int x2,int y2,int r2) {
    long long d = 1ll * (x2 - x1) * (x2 - x1) + 1ll * (y2 - y1) * (y2 - y1);
    return 1ll * (r1 - r2) * (r1 - r2) <= d && d <= 1ll * (r1 + r2) * (r1 + r2);
}

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void Union(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx != fy) f[fx] = fy;
}

void solve() {
    memset(f,0,sizeof f);
    int n,sx,sy,tx,ty,s,t;
    cin >> n >> sx >> sy >> tx >> ty;
    for (int i = 1;i <= n;i++) {
        int x,y,r;
        cin >> x >> y >> r;
        a[i] = {x,y,r},f[i] = i;
        if (check1(x,y,r,sx,sy)) s = i;
        if (check1(x,y,r,tx,ty)) t = i;
    }
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) {
            int x1 = a[i].x,y1 = a[i].y,r1 = a[i].r,x2 = a[j].x,y2 = a[j].y,r2 = a[j].r;
            if (check2(x1,y1,r1,x2,y2,r2)) Union(i,j);
        }
    cout << ((find(s) == find(t)) ? "Yes" : "No") << endl;
    return ;
}

int main() {
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}