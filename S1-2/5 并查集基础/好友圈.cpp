#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int f[N],size[N],cnt,ans = 0;

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void Union(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx == fy) return ;
    if (size[fx] < size[fy]) f[fx] = fy,size[fy] += size[fx],ans = max(ans,size[fy]);
    else f[fy] = fx,size[fx] += size[fy],ans = max(ans,size[fx]);
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) f[i] = i,size[i] = 1;
    cnt = n;
    while (m--) {
        int x,y;
        cin >> x >> y;
        if (find(x) != find(y)) {Union(x,y); cnt--;}
        cout << cnt << ' ' << ans << endl;
    }
    return 0;
}