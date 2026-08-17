#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
struct Edge {int s,t,c,col;} a[N];
int f[N],cnt,sum,v,e,need;

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void Union(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx != fy) f[fx] = fy;
}

void kruskal() {
    for (int i = 1;i <= e;i++) {
        int x = a[i].s,y = a[i].t;
        if (find(x) == find(y)) continue;
        if (a[i].col == 0) cnt++;
        sum += a[i].c;
        Union(x,y);
    }
    return ;
}

int main() {
    cin >> v >> e >> need;
    for (int i = 1;i <= e;i++) {
        cin >> a[i].s >> a[i].t >> a[i].c >> a[i].col;
        a[i].s++, a[i].t++;
    }
    int l = -100,r = 100,ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        for (int i = 1;i <= e;i++)
            if (a[i].col == 0) a[i].c += mid;
        for (int i = 1;i <= v;i++) f[i] = i;
        sort(a + 1,a + e + 1,[](Edge x,Edge y) {return x.c == y.c ? x.col < y.col : x.c < y.c;});
        cnt = 0, sum = 0;
        kruskal();
        if (cnt >= need) {
            l = mid + 1;
            ans = sum - need * mid;
        } else
            r = mid - 1;
        for (int i = 1;i <= e;i++)
            if (a[i].col == 0) a[i].c -= mid;
    }
    cout << ans << endl;
    return 0;
}