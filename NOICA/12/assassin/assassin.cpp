#include<iostream>
#include<queue>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1e5 + 5;
struct Node {int a,b; bool flag;} s[N];

void solve() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> s[i].a >> s[i].b;
        s[i].flag = false;
    }
    int minn = 1e18,id = 0;
    int njd = m,wq = 0,cnt = 0; // 剩余耐久度、武器使用次数、消灭人数
    for (int i = 1;i <= n;i++)
        if (s[i].b != 0 && s[i].a < minn)
            minn = s[i].a, id = i;
    if (id != 0)
        wq += s[id].b, njd -= s[id].a, s[id].flag = true, cnt++;
    sort(s + 1,s + n + 1,[](Node x,Node y) {return (x.b != y.b ? x.b > y.b : x.a > y.a);});
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    for (int i = 1;i <= n;i++) {
        if (s[i].flag) continue;
        if (wq != 0)
            wq--, wq += s[i].b, cnt++;
        else if (njd >= s[i].a) {
            njd -= s[i].a, wq += s[i].b, cnt++;
            q.push({s[i].b,s[i].a});
        }
        else if (!q.empty() && q.top().second < s[i].a) {
            njd += q.top().second, wq -= q.top().first; q.pop();
            njd -= s[i].a, wq += s[i].b;
            q.push({s[i].b, s[i].a});
            cnt++;
        }
    }
    cout << cnt << ' ' << m - njd << endl;
    return ;
}

signed main() {
    freopen("assassin.in","r",stdin);
    freopen("assassin.out","w",stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}