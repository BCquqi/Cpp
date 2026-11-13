#include<iostream>
#include<queue>
#include<vector>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int l[N],r[N],diff[N];
priority_queue<int> ql;
priority_queue<int,vector<int>,greater<int> > qr;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) 
        cin >> l[i] >> r[i], diff[i] = r[i] - l[i];
    int ls = 0,rs = 0,ans = 0;
    for (int i = 1;i <= n;i++) {
        ls -= diff[i],rs += diff[i - 1];
        if (!ql.empty() && l[i] - ls < ql.top()) {
            ans += ql.top() + ls - l[i];
            ql.push(l[i] - ls), ql.push(l[i] - ls);
            qr.push(ql.top() + ls - rs);
            ql.pop();
        } else if (!qr.empty() && l[i] - rs > qr.top()) {
            ans += l[i] - qr.top() - rs;
            qr.push(l[i] - rs), qr.push(l[i] - rs);
            ql.push(qr.top() + rs - ls);
            qr.pop();
        } else
            ql.push(l[i] - ls), qr.push(l[i] - rs);
    }
    cout << ans << endl;
    return 0;
}