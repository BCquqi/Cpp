#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e4 + 5;
vector<int> G[N];

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    for (int u = 1;u <= n;u++) {
        cout << u << ' ';
        sort(G[u].begin(),G[u].end());
        for (auto v : G[u]) cout << v << ' ';
        cout << endl;
    }
    return 0;
}