#include<iostream>
#include<vector>
using namespace std;

const int N = 2e5 + 5;
vector<int> G[N];
int fib[] = {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418},pos[N];
int siz[N],fa[N],sep;

void init(int u,int pa,int blocked) {
    siz[u] = 1;
    for (auto v : G[u]) {
        if (v == pa || v == blocked) continue;
        fa[v] = u;
        init(v,u,blocked);
        siz[u] += siz[v];
    }
}

void dfs(int u,int pa,int blocked,int id) {
    if (siz[u] == fib[id] || siz[u] == fib[id - 1]) sep = u;
    for (auto v : G[u]) {
        if (v == pa || v == blocked) continue;
        dfs(v,u,blocked,id);
    }
}

bool check(int u,int pa,int blocked) {
    init(u,pa,blocked);
    if (siz[u] <= 1) return true;
    int p = pos[siz[u]];
    if (p == 0) return false;
    sep = -1;
    dfs(u,pa,blocked,p - 1);
    if (sep == -1) return false;
    int f = fa[sep];
    for (auto it = G[f].begin();it != G[f].end();it++)
        if (*it == sep) {G[f].erase(it); break;}
    for (auto it = G[sep].begin();it != G[sep].end();it++)
        if (*it == f) {G[sep].erase(it); break;}
    while (f != u) siz[f] -= siz[sep], f = fa[f];
    siz[u] -= siz[sep];
    return check(u,sep,sep) && check(sep,u,u);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = 0;i <= 26;i++)
        pos[fib[i]] = i;
    if (check(1,0,0)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}