#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
int p[N],b[N],n,ans[N],c[N],m;
vector<int> G[N];

long long lowbit(long long x) {return x & -x;}
void change(long long x,long long t) {while (x <= n) c[x] += t,x += lowbit(x);}
long long sum(long long x) {
    long long ans = 0;
    while (x > 0) ans += c[x],x -= lowbit(x);
    return ans;
}

void dfs(int u) {
    long long s = sum(m) - sum(p[u]);
    change(p[u],1);
    for (auto v : G[u]) dfs(v);
    ans[u] = sum(m) - sum(p[u]) - s;
}

int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> p[i];
        b[i] = p[i];
    }
    for (int i = 2;i <= n;i++) {
        int f;
        cin >> f;
        G[f].push_back(i);
    }
    sort(b + 1,b + n + 1);
    m = unique(p + 1,p + n + 1) - p - 1;
    for (int i = 1;i <= n;i++) p[i] = lower_bound(b + 1,b + m + 1,p[i]) - b; 
    dfs(1);
    for (int i = 1;i <= n;i++) cout << ans[i] << endl;
    return 0;
}