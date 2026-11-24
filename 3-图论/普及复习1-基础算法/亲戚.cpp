#include<iostream>
using namespace std;

const int N = 5005;
int f[N];

int find(int u) {return u == f[u] ? u : f[u] = find(f[u]);}

void merge(int u,int v) {
    int fu = find(u),fv = find(v);
    if (fu != fv) f[fu] = fv;
}

int main() {
    int n,m,p;
    cin >> n >> m >> p;
    for (int i = 1;i <= n;i++) f[i] = i;
    while (m--) {
        int i,j;
        cin >> i >> j;
        merge(i,j);
    }
    while (p--) {
        int i,j;
        cin >> i >> j;
        if (find(i) == find(j)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}