#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5,M = 5e5 + 5;
struct Node {int i,j,m;} a[M];
int f[N],n,k;
long long sum = 0;

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void Union(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx != fy) f[fx] = fy;
}

long long kruskal() {
    long long ans = 0;
    for (int i = 1;i <= k;i++) {
        int u = a[i].i,v = a[i].j,w = a[i].m;
        if (find(u) == find(v)) continue;
        ans += w;
        Union(u,v);
    }
    return ans;
}

int main() {
    cin >> n >> k;
    for (int i = 1;i <= k;i++) {
        cin >> a[i].i >> a[i].j >> a[i].m;
        sum += a[i].m;
    }
    sort(a + 1,a + k + 1,[](Node x,Node y) {return x.m < y.m;});
    for (int i = 1;i <= n;i++) f[i] = i;
    long long ans = kruskal();
    cout << sum - ans << endl;
    return 0;
}