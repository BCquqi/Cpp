#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

const int N = 2e5 + 5;
struct Node {int u,v;};
bool operator < (const Node &x, const Node &y) {
    if (x.u != y.u) return x.u < y.u;
    return x.v < y.v;
}
map<Node,int> mp;
vector<int> G[N];
int dep[N];

void dfs(int u,int pa) {
    dep[u] = dep[pa] + 1;
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
    }
    return ;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n - 2;i++) {
        int pp,qq,rr;
        cin >> pp >> qq >> rr;
        int p = min(pp,min(qq,rr)), r = max(pp,max(qq,rr)), q = pp + qq + rr - p - r;
        if (mp[{p,q}]) {
            G[i].push_back(mp[{p,q}]);
            G[mp[{p,q}]].push_back(i);
        }
        else mp[{p,q}] = i;

        if (mp[{q,r}]) {
            G[i].push_back(mp[{q,r}]);
            G[mp[{q,r}]].push_back(i);
        }
        else mp[{q,r}] = i;

        if (mp[{p,r}]) {
            G[i].push_back(mp[{p,r}]);
            G[mp[{p,r}]].push_back(i);
        }
        else mp[{p,r}] = i;
    }
    dfs(1,0);
    int s,mxdep = 0;
    for (int i = 1;i <= n;i++)
        if (mxdep < dep[i]) mxdep = dep[i], s = i;
    memset(dep,0,sizeof dep);
    dfs(s,0);
    mxdep = 0;
    for (int i = 1;i <= n;i++)
        if (mxdep < dep[i]) mxdep = dep[i];
    cout << mxdep << endl;
    return 0;
}