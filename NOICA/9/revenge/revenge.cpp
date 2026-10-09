#include<iostream>
#include<algorithm>
#include<queue>
#define int long long
using namespace std;

const int N = 1e5 + 5;
struct Node {int a,b,id;} s[N], t[N];
bool operator < (const Node &x,const Node &y) {return x.a > y.a;}
bool cmp(Node x,Node y) {return x.a > y.a;}
int vis[N],ans[N],pre_b[N];

signed main() {
    freopen("revenge.in","r",stdin);
    freopen("revenge.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,p,k;
    cin >> n >> p >> k;
    int q = p - k;
    for (int i = 1;i <= n;i++) {
        cin >> s[i].a >> s[i].b;
        s[i].id = i;
    }
    sort(s + 1,s + n + 1,[](Node x,Node y) {return x.b != y.b ? x.b > y.b : (x.a != y.a ? x.a < y.a : x.id < y.id);});
    for (int i = 1;i <= n;i++) pre_b[i] = pre_b[i - 1] + s[i].b;
    priority_queue<Node> pq;
    int sum = 0;
    for (int i = 1;i <= k - 1;i++) {
        pq.push(s[i]);
        sum += s[i].a;
    }
    int d = -1,e = -1,f = -1;
    for (int i = k;i <= n - q;i++) {
        int tmp1 = sum + s[i].a;
        int tmp2 = pre_b[i + q] - pre_b[i];
        if (tmp1 > d || (tmp1 == d && tmp2 > e))
            d = tmp1, e = tmp2, f = i;
        if (i < n - q) {
            pq.push(s[i]);
            sum += s[i].a;
            if (pq.size() > k - 1) {
                sum -= pq.top().a;
                pq.pop();
            }
        }
    }
    for (int i = 1;i < f;i++) t[i] = s[i];
    sort(t + 1,t + f,cmp);
    for (int i = 1;i <= k - 1;i++) vis[t[i].id] = 1;
    vis[s[f].id] = 1;
    for (int i = f + 1;i <= f + q;i++) vis[s[i].id] = 1;
    int cur = 0;
    for (int i = 1;i <= n;i++)
        if (vis[i]) ans[++cur] = i;
    for (int i = 1;i <= cur;i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}