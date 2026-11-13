#include<iostream>
#include<queue>
using namespace std;

const int N = 1e6 + 5;
int t[N];
long long b[N],c[N];
priority_queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> t[i];
        t[i] -= i;
        q.push(t[i]);
        if (t[i] < q.top()) {
            ans += q.top() - t[i];
            q.pop();
            q.push(t[i]);
        }
        c[i] = q.top();
    }
    b[n] = c[n];
    for (int i = n - 1;i >= 1;i--)
        b[i] = min(b[i + 1],c[i]);
    cout << ans << endl;
    for (int i = 1;i <= n;i++)
        cout << b[i] + i << endl;
    return 0;
}