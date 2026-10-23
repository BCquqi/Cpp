#include<iostream>
using namespace std;

const int N = 3e7 + 5;
int phi[N],p[2000000],cnt;
long long sum[N];

int main() {
    int n = 3e7;
    phi[1] = 1;
    for (int i = 2;i <= n;i++) {
        if (!phi[i])
            p[++cnt] = i, phi[i] = i - 1;
        for (int j = 1;j <= cnt && i * p[j] <= n;j++) {
            if (i % p[j] == 0) {
                phi[i * p[j]] = phi[i] * p[j];
                break;
            }
            phi[i * p[j]] = phi[i] * (p[j] - 1);
        }
    }
    for (int i = 1;i <= n;i++) sum[i] = sum[i - 1] + phi[i];
    int T;
    cin >> T;
    for (int i = 1;i <= T;i++) {
        int n;
        cin >> n;
        cout << i << ' ' << n << ' ' << 2 * sum[n] + 1 << endl;
    }
    return 0;
}