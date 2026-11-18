#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 1005,M = 105,P = 131,mod = 998244353; // 希望不被卡模数
string file[N],folder[N];
long long hs1[N][M],hs2[N][M];

int main() {
    freopen("FileSkip.in","r",stdin);
    freopen("FileSkip.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> file[i];
        hs1[i][0] = file[i][0];
        for (int j = 1;j < file[i].size();j++)
            hs1[i][j] = (hs1[i][j - 1] * P % mod + file[i][j]) % mod;
    }
    for (int i = 1;i <= m;i++) {
        cin >> folder[i];
        hs2[i][0] = folder[i][0];
        for (int j = 1;j < folder[i].size();j++)
            hs2[i][j] = (hs2[i][j - 1] * P % mod + folder[i][j]) % mod;
    }
    for (int i = 1;i <= n;i++) {
        bool flag = false;
        for (int j = 1;j <= m;j++)
            if (hs2[j][folder[j].size() - 1] == hs1[i][folder[j].size() - 1]) {
                flag = true;
                break;
            }
        if (!flag) cout << file[i] << '\n';
    }
    return 0;
}