#include<iostream>
using namespace std;

const int N = 1e7 + 5;
long long phi[N],sum[N],p[N];
int cnt = 0;

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) phi[i] = i;
    for (int i = 2;i <= n;i++) {
        if (phi[i] == i) {
            p[++cnt] = i;
            for (int j = i;j <= n;j += i)
                phi[j] = phi[j] / i * (i - 1);
        }
    }
    for (int i = 1;i <= n;i++)
        sum[i] = sum[i - 1] + phi[i];
    long long ans = 0;
    for (int i = 1;i <= cnt;i++)
        ans += 2 * sum[n / p[i]] - 1;
    cout << ans << endl;
    return 0;
}