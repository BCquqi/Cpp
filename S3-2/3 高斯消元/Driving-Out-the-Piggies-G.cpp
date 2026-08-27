#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

const int N = 305;
const double eps = 1e-9;
vector<int> G[N];
int n,m,deg[N];
double p,q,a[N][N],x[N];

void rowopr(double r1[],double r2[],double k) {for (int j = 1;j <= n + 1;j++) r1[j] += r2[j] * k;}

int Gauss(double a[][N]) {
    int r = 1;
    for (int j = 1;j <= n;j++) {
        int i = r;
        while (i <= n && abs(a[i][j]) <= eps) i++;
        if (i > n) continue;
        swap(a[r],a[i]);
        for (int i = r + 1;i <= n;i++)
            rowopr(a[i],a[r],-1 * a[i][j] / a[r][j]);
        r++;
    }
    if (--r < n) {
        for (int i = r + 1;i <= n;i++)
            if (abs(a[i][n + 1]) > eps) return -1;
        return 0;
    }
    for (int i = n;i >= 1;i--) {
        x[i] = a[i][n + 1];
        for (int j = i + 1;j <= n;j++)
            x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
    }
    return 1;
}

int main() {
    cin >> n >> m >> p >> q;
    for (int i = 1;i <= m;i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
        deg[a]++, deg[b]++;
    }
    for (int u = 1;u <= n;u++) {
        a[u][u] = 1;
        for (auto v : G[u])
            a[u][v] -= (1 - p / q) * (1.0 / deg[v]);
        a[u][n + 1] = (u == 1);
    }
    Gauss(a);
    for (int i = 1;i <= n;i++)
        printf("%.9lf\n",x[i] * (p / q));
    return 0;
}