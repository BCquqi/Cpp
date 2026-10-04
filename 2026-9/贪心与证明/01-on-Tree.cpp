#include<iostream>
#include<vector>
#include<queue>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int p[N],cnt0[N],cnt1[N],f[N];
struct cmp {
    int id,cnt0,cnt1;
    bool operator() (cmp a,cmp b) const {return a.cnt1 * b.cnt0 != b.cnt1 * a.cnt0 ? a.cnt1 * b.cnt0 > b.cnt1 * a.cnt0 : a.id > b.id;}
};
priority_queue<cmp,vector<cmp>,cmp> q;

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void Union(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx != fy) f[fx] = fy;
}

signed main() {
    int n;
    cin >> n;
    for (int i = 2;i <= n;i++)
        cin >> p[i];
    for (int i = 1;i <= n;i++) {
        int v;
        cin >> v;
        if (v) cnt1[i]++;
        else cnt0[i]++;
        f[i] = i;
    }
    for (int i = 2;i <= n;i++) q.push({i,cnt0[i],cnt1[i]});
    int ans = 0;
    while (!q.empty()) {
        auto [tmp,tmp0,tmp1] = q.top(); q.pop();
        if (find(tmp) != tmp) continue; // 防止多个儿子重复将根入队
        int fa = find(p[tmp]);
        ans += cnt1[fa] * cnt0[tmp];
        cnt0[fa] += cnt0[tmp], cnt1[fa] += cnt1[tmp];
        Union(tmp,fa);
        if (fa != 1) q.push({fa,cnt0[fa],cnt1[fa]});
    }
    cout << ans << endl;
    return 0;
}