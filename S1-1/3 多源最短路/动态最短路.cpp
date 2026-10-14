#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 205;
struct Edge {int v,w;};
vector<Edge> G[N];

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
    }
    int q;
    cin >> q;
    while (q--) {
        string op;
        cin >> op;
        if (op == "add")
    }
    return 0;
}