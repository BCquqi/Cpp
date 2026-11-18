#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define int long long
using namespace std;

const int N = 55;
vector<int> G[N];
int deg[N];
bool vis[N];

/*
给定一个无根树，两人轮流进行操作：
选定点 (u,v) 将 u 除了 [u <-> v] 外其他连边 [u <-> w] 都变成 [v <-> w]
改变后和改变前的树不能同构
若无法改变则一方失败
在两人都采取最优策略下，求谁会获胜
*/

// 树的同构: 结构相同 内部编号可以不同
// 题目性质: 无法继续进行重构操作，当且仅当形成了菊花图
/*
1. 贪心钦定邻接节点个数最多的点为菊花中心
2. 菊花中心连点标记为 true
3. 开始传递连边 -- 对于每个 true 节点，将其非子树根直接连到菊花中心上，子树根标为 true
显然上述过程可以用 BFS 平替了
直连过程通过入队等表示即可, 显然无需实际连图
标记为 true 就是入队了
*/

void solve() {
    int n;
    cin >> n;
    if (n <= 1) {
        cout << "villager" << endl;
        return;
    }
    for (int i = 1;i <= n;i++) G[i].clear();
    memset(vis,false,sizeof vis);
    memset(deg,0,sizeof deg);
    for (int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    int maxn = -1, root = 1;
    for (int i = 1;i <= n;i++)
        if (deg[i] > maxn) maxn = deg[i], root = i;
    queue<int> q;
    q.push(root), vis[root] = true;
    for (auto v : G[root]) q.push(v), vis[v] = true; // 菊花中心和连点
    int ans = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : G[u]) {
            if (vis[v]) continue;
            vis[v] = true, q.push(v);
            ans++;
        }
    }
    if (ans % 2 == 1) cout << "wizard" << endl;
    else cout << "villager" << endl;
    return ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("forest.in","r",stdin);
    freopen("forest.out","w",stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}