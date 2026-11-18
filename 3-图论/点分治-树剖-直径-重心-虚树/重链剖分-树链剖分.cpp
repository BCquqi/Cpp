#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
int a[N],dep[N],fa[N];
vector<int> G[N];

void dfs(int u,int pa) {
    dep[u] = dep[pa] + 1, fa[u] = pa;
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
    }
}

int main() {
    int n,m,r,p;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i < n;i++) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y); G[y].push_back(x);
    }
    while (m--) {
        int op;
        cin >> op;
        switch (op)
        {
            case 1 : {
                int x,y,z;
                cin >> x >> y >> z;
                
                break;
            }
        }
    }
    return 0;
}