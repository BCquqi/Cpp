#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const double eps = 1e-6;
const int N = 15;
double a[N][N],b[N][N],x[N];
int n;

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
    scanf("%d",&n);
    for (int i = 1;i <= n + 1;i++)
        for (int j = 1;j <= n;j++)
            scanf("%lf",&a[i][j]);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            b[i][j] = 2 * (a[i + 1][j] - a[i][j]), 
            b[i][n + 1] += a[i + 1][j] * a[i + 1][j] - a[i][j] * a[i][j];
    Gauss(b);
    for (int i = 1;i <= n;i++) printf("%.3lf ",x[i]);
    printf("\n");
    return 0;
}