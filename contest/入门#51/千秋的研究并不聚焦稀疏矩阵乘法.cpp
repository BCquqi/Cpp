#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 5005;
int a[N][N];
long long s[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + abs(a[i][j]);
        }
    long long ans = 1e18;
    int id;
    for (int k = n;k >= 1;k--) {
        int num = 1ll * ((n + k - 1) / k) * ((n + k - 1) / k);
        for (int i = 1;i <= n;i += k)
            for (int j = 1;j <= n;j += k) {
                int x = min(i + k - 1,n), y = min(j + k - 1,n);
                if (s[x][y] - s[i - 1][y] - s[x][j - 1] + s[i - 1][j - 1] == 0) num--;
            }
        if (1ll * num * (1ll * k * k + 1) < ans) ans = 1ll * num * (1ll * k * k + 1), id = k;
    }
    cout << id << ' ' << ans << endl;
    return 0;
}