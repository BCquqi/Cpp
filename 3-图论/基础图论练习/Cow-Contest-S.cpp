#include<iostream>
#include<cstring>
using namespace std;

const int N = 105;
bool f[N][N];
int n,m;

int main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x,y;
        cin >> x >> y;
        f[x][y] = true;
    }
    for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                f[i][j] |= f[i][k] && f[k][j];
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        int cnt = 0;
        for (int j = 1;j <= n;j++)
            if (i != j && (f[i][j] || f[j][i])) cnt++;
        if (cnt == n - 1) ans++;
    }
    cout << ans << endl;
    return 0;
}