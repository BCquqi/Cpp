#include<iostream>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

const int M = 210;
int pre[M][M];

inline int basev(int x, int y) {return ((x + y) & 1) ? 1 : -1;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("two.in","r",stdin);
    freopen("two.out","w",stdout);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        set<pair<int,int> > key;
        for (int i = 1; i <= k; i++) {
            int x, y;
            cin >> x >> y;
            key.insert({x, y});
        }
        if (k == 0) {
            cout << 1 << endl;
            continue;
        }
        set<int> row, col;
        row.insert(1); row.insert(n);
        col.insert(1); col.insert(n);
        for (auto [x, y] : key) {
            for (int dx = -1; dx <= 1; dx++) {
                int nx = x + dx;
                if (1 <= nx && nx <= n) row.insert(nx);
            }
            for (int dy = -1; dy <= 1; dy++) {
                int ny = y + dy;
                if (1 <= ny && ny <= n) col.insert(ny);
            }
        }
        vector<int> X(row.begin(), row.end());
        vector<int> Y(col.begin(), col.end());
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        int m = X.size(), t = Y.size();
        memset(pre, 0, sizeof pre);
        for (auto [x, y] : key) {
            int i = lower_bound(X.begin(), X.end(), x) - X.begin();
            int j = lower_bound(Y.begin(), Y.end(), y) - Y.begin();
            pre[i + 1][j + 1] += basev(x, y);
        }
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= t; j++)
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + pre[i][j];
        long long ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = i; j < m; j++) {
                int x1 = X[i], x2 = X[j];
                for (int p = 0; p < t; p++) {
                    for (int q = p; q < t; q++) {
                        int y1 = Y[p], y2 = Y[q];
                        long long base = 0;
                        int w = x2 - x1 + 1;
                        int h = y2 - y1 + 1;
                        if ((w & 1) && (h & 1)) base = basev(x1, y1);
                        long long flip = 0;
                        int l = i, r = j;
                        int u = p, v = q;
                        flip = pre[r + 1][v + 1] - pre[l][v + 1] - pre[r + 1][u] + pre[l][u];
                        long long sum = base - 2LL * flip;
                        ans = max(ans, llabs(sum));
                    }
                }
            }
        cout << ans << endl;
    }
    return 0;
}