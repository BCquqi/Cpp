#include <algorithm>
#include <iostream>
using namespace std;

const int N = 505,M = 1005;
int n,S;
struct Node {int in,out,w,s,v;} a[N];
int inside[N][M],f[N + 1][M],order[N],start[N],timeList[N],idList[N];

void init() {
    for (int i = 1;i <= n;i++)
        start[i] = order[i] = i + 1;
    sort(start, start + n, [](int x, int y) {return a[x].in != a[y].in ? a[x].in < a[y].in : a[x].out > a[y].out;});
    sort(order, order + n, [](int x, int y) {return a[x].out - a[x].in < a[y].out - a[y].in;});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> S;
    for (int i = 1;i <= n;i++)
        cin >> a[i].in >> a[i].out >> a[i].w >> a[i].s >> a[i].v;
    init();
    for (int t = 0; t < n; ++t) {
        int u = order[t];
        int m = 0;
        for (int k = 0; k < n; ++k) {
            int i = start[k];
            if (i != u && a[u].in <= a[i].in && a[i].in < a[u].out) {
                idList[m] = i;
                timeList[m++] = a[i].in;
            }
        }

        for (int i = 0; i <= m; ++i) {
            fill(f[i], f[i] + S + 1, 0);
        }

        for (int k = m - 1; k >= 0; --k) {
            int i = idList[k];
            int nxt = lower_bound(timeList + k + 1, timeList + m, a[i].out) - timeList;
            for (int c = 0; c <= S; ++c) {
                f[k][c] = f[k + 1][c];
                if (a[i].out <= a[u].out && a[i].w <= c) {
                    int cap = min(a[i].s, c - a[i].w);
                    f[k][c] = max(f[k][c], a[i].v + inside[i][cap] + f[nxt][c]);
                }
            }
        }

        for (int c = 0; c <= S; ++c)
            inside[u][c] = f[0][c];
    }

    for (int i = 0; i < n; ++i)
        timeList[i] = a[start[i]].in;
    for (int i = 0; i <= n; ++i) {
        fill(f[i], f[i] + S + 1, 0);
    }

    for (int k = n - 1; k >= 0; --k) {
        int i = start[k];
        int nxt = lower_bound(timeList + k + 1, timeList + n, a[i].out) - timeList;
        for (int c = 0; c <= S; ++c) {
            f[k][c] = f[k + 1][c];
            if (a[i].w <= c) {
                int cap = min(a[i].s, c - a[i].w);
                f[k][c] = max(f[k][c], a[i].v + inside[i][cap] + f[nxt][c]);
            }
        }
    }
    cout << f[0][S] << '\n';
    return 0;
}
