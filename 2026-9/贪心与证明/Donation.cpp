#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 2e5 + 5;
struct Node {int u,v; long long w;} a[2 * N];

vector<int> tree[2 * N];

long long A[N],B[N],C[N],sumB[2 * N],ans[2 * N];
int n,m,f[2 * N],cnt,treew[2 * N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void kruskal() {
    sort(a + 1,a + m + 1,[](Node x,Node y) {return x.w < y.w;});
    for (int i = 1;i <= 2 * n;i++) f[i] = i;
    cnt = n;
    for (int i = 1;i <= m;i++) {
        int u = a[i].u,v = a[i].v;
        if (find(u) == find(v)) continue;
        cnt++;
        tree[cnt].push_back(find(u)); tree[find(u)].push_back(cnt);
        tree[cnt].push_back(find(v)); tree[find(v)].push_back(cnt);
        f[find(u)] = f[find(v)] = cnt, treew[cnt] = a[i].w;
    }
}

void dfs_sum(int u,int pa) {
    sumB[u] = (u <= n ? B[u] : 0);
    for (auto v : tree[u]) {
        if (v == pa) continue;
        dfs_sum(v,u);
        sumB[u] += sumB[v];
    }
}

void dfs_ans(int u,int pa,long long max_cost) {
    if (u <= n) {
        ans[u] = max(A[u],max_cost);
        return;
    }
    for (auto v : tree[u]) {
        if (v == pa) continue;
        long long cost = treew[u] - sumB[v];
        dfs_ans(v,u,max(max_cost,cost));
    }
}

int main() {
    memset(f,0,sizeof f); memset(ans,0,sizeof ans);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> A[i] >> B[i];
        C[i] = max(A[i] - B[i],0LL);
    }
    for (int i = 1;i <= m;i++) {
        cin >> a[i].u >> a[i].v;
        a[i].w = max(C[a[i].u],C[a[i].v]);
    }
    kruskal();
    dfs_sum(cnt,0);
    dfs_ans(cnt,0,0);
    long long res = 1e18;
    for (int i = 1;i <= n;i++) res = min(res,ans[i]);
    cout << res << endl;
    return 0;
}