#include<iostream>
using namespace std;

const int N = 2e6 + 5;
int f[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void Union(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx != fy) f[fx] = fy;
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) f[i] = i;
    while (m--) {
        int z,x,y;
        cin >> z >> x >> y;
        if (z == 1) Union(x,y);
        else cout << ((find(x) == find(y)) ? "Y" : "N") << endl;
    }
    return 0;
}