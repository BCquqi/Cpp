#include<iostream>
#include<queue>
#define int long long
using namespace std;

/*
因为 a[i] >= 0，所以对每个 r 选 l = 1 一定最优
然后呢就可以维护最大值，如果当前 r 对应的 l 被选走就把 [l + 1,r] 放进来
*/

const int N = 1e5 + 5;
int sum[N],a[N];
struct Node {int val,l,r;};
bool operator < (const Node &x,const Node &y) {return x.val < y.val;}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("volume.in","r",stdin);
    freopen("volume.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    priority_queue<Node> q;
    for (int i = 1;i <= n;i++) q.push({sum[i],1,i});
    for (int i = 1;i <= k;i++) {
        auto it = q.top(); q.pop();
        cout << it.val << ' ';
        if (it.l < it.r)
            q.push({sum[it.r] - sum[it.l],it.l + 1,it.r});
    }
    cout << endl;
    return 0;
}