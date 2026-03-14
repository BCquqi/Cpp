#include<iostream>
#include<vector>
using namespace std;

const int N = 1e3 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];

int main() {
    int n,m,x;
    cin >> n >> m >> x;
    for (int i = 1;i <= m;i++) {
        int a,b,t;
        cin >> a >> b >> t;
        G[a].push_back({b,t});
        for (auto u : G[a])
            if (u.v == b) {
                u.w = min(u.w,t);
                break;
            }
    }
    return 0;
}