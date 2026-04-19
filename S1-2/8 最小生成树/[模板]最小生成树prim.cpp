#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e4 + 5;
struct Node {int v,w;};
vector<Node> G[N];
int dis[N],ans = 0,cnt = 0; bool vis[N];

bool operator < (const Node &x,const Node &y) {return x.w > y.w;}

void prim() {
    memset(dis,0x3f,sizeof dis);
    memset(vis,false,sizeof vis);
    priority_queue<Node> q;
    q.push({1,0});
    dis[1] = 0;
    cnt = 0,ans = 0;
    while (!q.empty()) {
        int u = q.top().v,d = q.top().w; q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        ans += d,cnt++;
        for (auto [v,w] : G[u]) {
            if (dis[v] <= w) continue;
            dis[v] = w;
            q.push({v,dis[v]});
        }
    }
    return ;
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        G[x].push_back({y,z}); G[y].push_back({x,z});
    }
    prim();
    if (cnt != n) cout << "orz" << endl;
    else cout << ans << endl;
    return 0;
}