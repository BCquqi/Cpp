#include<iostream>
#include<queue>
#include<vector>
#define int long long
using namespace std;

priority_queue<int> q1;
priority_queue<int, vector<int>, greater<int>> q2;
int s1 = 0,s2 = 0,sum = 0;

void insert(int a) {
    if (q1.empty() || a <= q1.top())
        s1 += a, q1.push(a);
    else
        s2 += a, q2.push(a);
    if (q1.size() > q2.size() + 1) {
        int v = q1.top();
        q1.pop();
        s1 -= v;
        q2.push(v);
        s2 += v;
    } else if (q1.size() < q2.size()) {
        int v = q2.top();
        q2.pop();
        s2 -= v;
        q1.push(v);
        s1 += v;
    }
    return ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            sum += b;
            insert(a);
        } else {
            int mid = q1.top();
            int ans = mid * q1.size() - s1 + s2 - mid * q2.size() + sum;
            cout << mid << ' ' << ans << endl;
        }
    }
    return 0;
}