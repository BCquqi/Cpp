#include<iostream>
#define int long long
using namespace std;

const int N = 105,mod = 1e9 + 7;
struct Matrix {int a[N][N];};
int n,k;
Matrix ans,m;

Matrix operator *(const Matrix &x,const Matrix &y) {
    Matrix ret;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) ret.a[i][j] = 0;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            for (int k = 1;k <= n;k++)
                ret.a[i][j] = (ret.a[i][j] + x.a[i][k] * y.a[k][j] % mod + mod) % mod;
    return ret;
}

void qpow(Matrix a,int b) {
    while (b) {
        if (b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
}

signed main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) cin >> m.a[i][j];
    for (int i = 1;i <= n;i++) ans.a[i][i] = 1;
    qpow(m,k);
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) cout << ans.a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}