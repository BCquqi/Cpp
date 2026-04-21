#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 505,M = 3e5 + 5;
struct Node {int u,v; double w;} a[M];
double x[N],y[N];
int n,k,cur = 0,cnt = 0,f[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void Union(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx != fy) f[fx] = fy;
}

double kruskal() {
	if (n == k) return 0;
    double ans = 0;
    for (int i = 1;i <= cur;i++) {
        int u = a[i].u,v = a[i].v;
        double w = a[i].w;
        if (find(u) == find(v)) continue;
        Union(u,v);
        ans = w;
        if (++cnt == n - k) break;
    }
    return ans;
}

int main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) cin >> x[i] >> y[i];
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            a[++cur] = {i,j,sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]))};
    sort(a + 1,a + cur + 1,[](Node x,Node y) {return x.w < y.w;});
    for (int i = 1;i <= n;i++) f[i] = i;
    printf("%.2lf",kruskal());
    return 0;
}