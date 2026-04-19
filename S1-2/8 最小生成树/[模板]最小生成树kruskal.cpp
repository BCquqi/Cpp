#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e4 + 5,M = 1e5 + 5;
struct Node {int x,y,z;} a[M];
int f[N],cnt = 0,n,m;

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void Union(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx != fy) f[fx] = fy;
}

int kruskal() {
    for (int i = 1;i <= n;i++) f[i] = i;
    int ans = 0;
    for (int i = 1;i <= m;i++) {
        int x = a[i].x,y = a[i].y,z = a[i].z;
        if (find(x) == find(y)) continue;
        ans += z;
        Union(x,y);
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++)
        cin >> a[i].x >> a[i].y >> a[i].z;
    sort(a + 1,a + m + 1,[](Node x,Node y){return x.z < y.z;});
    int ans = kruskal();
    for (int i = 1;i <= n;i++)
        if (f[i] == i) cnt++;
    if (cnt > 1) cout << "orz" << endl;
    else cout << ans << endl;
    return 0;
}