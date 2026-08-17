#include<iostream>
using namespace std;

const int N = 1005;
int n,m,a[N][N],s[N][N];

void solve() {
    bool special = true;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) {
            cin >> a[i][j];
            special &= (!a[i][j]);
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    long long ans = 0;
    for (int x1 = 1;x1 <= n;x1++)
        for (int y1 = 1;y1 <= m;y1++)
            for (int x2 = x1;x2 <= n;x2++)
                for (int y2 = y1;y2 <= m;y2++) {
                    if (s[x2][y2] - s[x1][y1 - 1] - s[x1 - 1][y1] + s[x1 - 1][y1 - 1] != 0) continue;
                    for (int x3 = 1;x3 <= n;x3++)
                        for (int y3 = 1;y3 <= m;y3++) {
                            if (x3 < x2 && y3 < y2) continue;
                            for (int x4 = x3;x4 <= n;x4++)
                                for (int y4 = y3;y4 <= m;y4++) {
                                    if (x1 < x4 && y1 < y4) continue;
                                    if (s[x4][y4] - s[x3][y3 - 1] - s[x3 - 1][y3] + s[x3 - 1][y3 - 1] != 0) continue;
                                    ans++;
                                }
                        }
                }
    cout << ans / 2 << endl;
    return ;
}

int main() {
    freopen("allocation.in","r",stdin);
    freopen("allocation.out","w",stdout);
    while (cin >> n >> m) solve();
    return 0;
}