#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N],bamboo,ans;
int maxn[N];

void dfs(int u,int pa) {
    maxn[u] = 0;
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        maxn[u] = max(maxn[u], maxn[v]);
    }
    maxn[u]++;
}

void check(int u,int pa) {
    multiset<pair<int,int>> s;
    for (auto v : G[u]) {
        if (v == pa) continue;
        s.insert(make_pair(maxn[v],v));
    }
    if (s.empty()) return;
    for (auto v = s.begin();v != s.end();v++) {
        bamboo.push_back(v -> second);
        check(v -> second,u);
    }
    int cur = s.begin() -> first;
    for (auto v = s.begin();v != s.end();v++) {
        if (v == s.begin()) continue;
        for (int i = 1;i <= cur;i++)
            ans.push_back(v -> second);
        cur = v -> first;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i < n;i++) {
        int p;
        cin >> p;
        G[i].push_back(p), G[p].push_back(i);
    }
    dfs(0,-1);
    check(0,-1);
    cout << 0 << ' ';
    for (auto id : bamboo) cout << id << ' ';
    cout << endl << ans.size() << endl;
    for (auto v : ans) cout << v << ' ';
    cout << endl;
    return 0;
}