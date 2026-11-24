#include<iostream>
using namespace std;

const int N = 4e6 + 5;
int f[N];

int find(int u) {return u == f[u] ? u : f[u] = find(f[u]);}

void merge(int u,int v) {
    int fu = find(u),fv = find(v);
    if (fu != fv) f[fu] = fv;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) f[i] = i;
    long long ans = 0;
    const int mod = 998244353;
    while (m--) {
        int z,x,y;
        cin >> z >> x >> y;
        if (z == 0) merge(x,y);
        else ans = ans << 1 | (find(x) == find(y)), ans %= mod;
    }
    cout << ans << endl;
    return 0;
}