#include<iostream>
#include<queue>
#define int long long
using namespace std;

const int N = 3e5 + 5;
struct List {int pre,nxt,val;} a[N];
struct Node {
    int id,val;
    bool operator < (Node x) const {return val < x.val;}
}; 
bool vis[N];
priority_queue<Node> q;

void del(int x) {
    a[a[x].pre].nxt = a[x].nxt,
    a[a[x].nxt].pre = a[x].pre, 
    vis[x] = true;
}

signed main() {
    int n,k,ans = 0;
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].val;
        a[i - 1].nxt = i, a[i].pre = i - 1;
        q.push({i,a[i].val});
    }
    a[0].val = a[n + 1].val = -1e18;
    a[0].nxt = 1, a[1].pre = 0, a[n].nxt = n + 1, a[n + 1].pre = n;
    for (int i = 1;i <= k;i++) {
        while (vis[q.top().id]) q.pop();
        if (q.top().val <= 0) break;
        ans += q.top().val;
        a[q.top().id].val = a[a[q.top().id].pre].val + a[a[q.top().id].nxt].val - a[q.top().id].val;
        del(a[q.top().id].pre);
        del(a[q.top().id].nxt);
        int cpy1 = q.top().id,cpy2 = a[q.top().id].val;
        q.pop();
        q.push({cpy1,cpy2}); 
    }
    cout << max(ans,0ll) << endl;
    return 0;
}