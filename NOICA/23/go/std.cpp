#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)4e18;

int N, K, E, M;
vector<ll> S, T;
vector<vector<ll>> dist;
vector<vector<ll>> tv;
int maxP, stride;

int ID(int node, int p, int st) { return node * stride + p * 2 + st; }

int idxOf(int node, ll t) {
    return (int)(lower_bound(tv[node].begin(), tv[node].end(), t) - tv[node].begin());
}

int main() {
    scanf("%d %d", &N, &K);
    S.resize(K); T.resize(K);
    for (int i = 0; i < K; i++) scanf("%lld", &S[i]);
    for (int i = 0; i < K; i++) scanf("%lld", &T[i]);
    scanf("%d", &M);
    scanf("%d", &E);

    dist.assign(N, vector<ll>(N, INF));
    for (int i = 0; i < N; i++) dist[i][i] = 0;
    for (int i = 0; i < E; i++) {
        int a, b; ll c;
        scanf("%d %d %lld", &a, &b, &c);
        if (c < dist[a][b]) { dist[a][b] = c; dist[b][a] = c; }
    }
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (dist[i][k] < INF && dist[k][j] < INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    tv.assign(N, vector<ll>());
    for (int i = 0; i < N; i++) tv[i].push_back(0);
    for (int k = 0; k < K; k++) {
        ll L = S[k], R = T[k];
        for (int i = 0; i < N; i++) {
            tv[i].push_back(L);
            tv[i].push_back(R);
            for (int j = 0; j < N; j++) {
                if (dist[j][i] < INF && L + dist[j][i] <= R) tv[i].push_back(L + dist[j][i]);
                if (dist[i][j] < INF && R - dist[i][j] >= L) tv[i].push_back(R - dist[i][j]);
            }
        }
    }
    maxP = 0;
    for (int i = 0; i < N; i++) {
        sort(tv[i].begin(), tv[i].end());
        tv[i].erase(unique(tv[i].begin(), tv[i].end()), tv[i].end());
        if ((int)tv[i].size() > maxP) maxP = (int)tv[i].size();
    }
    stride = maxP * 2;
    int V = N * stride;
    vector<vector<pair<int,ll>>> adj(V);

    for (int i = 0; i < N; i++) {
        int m = (int)tv[i].size();
        for (int p = 0; p < m; p++) {
            adj[ID(i, p, 0)].push_back(make_pair(ID(i, p, 1), (ll)M));
            adj[ID(i, p, 1)].push_back(make_pair(ID(i, p, 0), 0));
            if (p + 1 < m) {
                ll dt = tv[i][p + 1] - tv[i][p];
                adj[ID(i, p, 0)].push_back(make_pair(ID(i, p + 1, 0), dt));
                adj[ID(i, p + 1, 1)].push_back(make_pair(ID(i, p, 1), dt));
            }
        }
    }

    for (int k = 0; k < K; k++) {
        ll L = S[k], R = T[k], len = R - L;
        for (int u = 0; u < N; u++) {
            for (int v = 0; v < N; v++) {
                if (u == v) continue;
                ll c = dist[u][v];
                if (c >= INF || c > len) continue;
                int pu = idxOf(u, L);
                int qv = idxOf(v, L + c);
                adj[ID(u, pu, 0)].push_back(make_pair(ID(v, qv, 0), c));
                int pu2 = idxOf(u, R - c);
                int qv2 = idxOf(v, R);
                adj[ID(u, pu2, 0)].push_back(make_pair(ID(v, qv2, 0), c));
            }
        }
    }

    vector<ll> d(V, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    int src = ID(0, idxOf(0, 0), 0);
    d[src] = 0;
    pq.push(make_pair((ll)0, src));

    while (!pq.empty()) {
        ll cur = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if (cur > d[x]) continue;
        for (size_t e = 0; e < adj[x].size(); e++) {
            int y = adj[x][e].first;
            ll w = adj[x][e].second;
            if (cur + w < d[y]) { d[y] = cur + w; pq.push(make_pair(d[y], y)); }
        }
    }

    int m = (int)tv[N - 1].size();
    ll ans = INF;
    for (int p = 0; p < m; p++) {
        ll val = d[ID(N - 1, p, 0)];
        if (val < ans) ans = val;
    }
    if (ans >= INF) printf("-1\n"); else printf("%lld\n", ans);
    return 0;
}
