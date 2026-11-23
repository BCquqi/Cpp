#include<iostream>
#include<cstring>
#define int long long
using namespace std;

const int N = 5,mod = 1e9 + 7;
struct Matrix {int a[N][N];};
int n;
Matrix ans,m;

Matrix operator *(const Matrix &x,const Matrix &y) {
    Matrix ret;
    for (int i = 1;i <= 3 ;i++)
        for (int j = 1;j <= 3;j++) ret.a[i][j] = 0;
    for (int i = 1;i <= 3;i++)
        for (int j = 1;j <= 3;j++)
            for (int k = 1;k <= 3;k++)
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

void solve() {
    cin >> n;
    if (n <= 3) {
        cout << 1 << endl;
        return ;
    }
    memset(m.a,0,sizeof m.a);
    m.a[1][1] = m.a[2][1] = m.a[1][3] = m.a[3][2] = 1;
    memset(ans.a,0,sizeof ans.a);
    for (int i = 1;i <= 3;i++) ans.a[i][i] = 1;
    qpow(m,n);
    cout << ans.a[2][1] << endl;
    return ;
}

signed main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}