#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int f[N];
long long d[N];

int find(int x) {
    if (f[x] == x) return x;
    int root = find(f[x]);
    d[x] += d[f[x]];
    return f[x] = root;
}

void Union(int x,int y,long long s) {
    int fx = find(x),fy = find(y);
    if (fx == fy) return ;
    f[fx] = fy,d[fx] = d[y] - d[x] - s;
}

int main() {
    int n,m,q;
    cin >> n >> m >> q;
    for (int i = 1;i <= n;i++) f[i] = i;
    while (m--) {
        int l,r;
        long long s;
        cin >> l >> r >> s;
        Union(l - 1,r,s);
    }
    while (q--) {
        int l,r;
        cin >> l >> r;
        if (find(l - 1) == find(r)) cout << d[r] - d[l - 1] << endl;
        else cout << "UNKNOWN" << endl;
    }
    return 0;
}