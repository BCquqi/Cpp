#include<iostream>
using namespace std;

const int N = 2e5 + 5;
int f[N];

int find(int u) {return u == f[u] ? u : f[u] = find(f[u]);}

void merge(int u,int v) {
    int fu = find(u),fv = find(v);
    if (fu != fv) f[fu] = fv;
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) f[i] = i;
    while (m--) {
        int z,x,y;
        cin >> z >> x >> y;
        if (z == 1) merge(x,y);
        else cout << (find(x) == find(y) ? 'Y' : 'N') << endl;
    }
    return 0;
}