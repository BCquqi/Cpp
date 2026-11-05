#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int a[N],ans[N],cur = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("queue.in","r",stdin);
    freopen("queue.out","w",stdout);
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        if (i != n && sum == 1ll * i * (i + 1) / 2)
            ans[++cur] = i;
    }
    cout << cur << endl;
    for (int i = 1; i <= cur; i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}