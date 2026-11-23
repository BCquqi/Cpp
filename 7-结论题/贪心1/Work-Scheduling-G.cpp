#include<iostream>
#include<queue>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1e5 + 5;
struct Node {int d,p;} s[N];
priority_queue<int,vector<int>,greater<int> > q;

signed main() {
    int n,ans = 0;
    cin >> n;
    for (int i = 1;i <= n;i++)
        cin >> s[i].d >> s[i].p;
    sort(s + 1,s + n + 1,[](Node x,Node y) {return x.d < y.d;});
    for (int i = 1;i <= n;i++) {
        if (s[i].d > q.size()) {
            ans += s[i].p;
            q.push(s[i].p);
        } else if (s[i].p > q.top()) {
            ans -= q.top(); q.pop();
            ans += s[i].p; q.push(s[i].p);
        }
    }
    cout << ans << endl;
    return 0;
}
