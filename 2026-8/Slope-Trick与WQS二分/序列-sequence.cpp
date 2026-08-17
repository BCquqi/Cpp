#include<iostream>
#include<queue>
using namespace std;

const int N = 5e5 + 5;
int a[N];
priority_queue<int> q;

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    long long ans = 0;
    for (int i = 1;i <= n;i++) {
        q.push(a[i]);
        if (q.top() > a[i]) {
            ans += q.top() - a[i];
            q.pop(); q.push(a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}