#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int a[N],b[N],lg[N],stmax[N][30],stmin[N][30],stmax2[N][30],stmin2[N][30],stbmax[N][30],stbmin[N][30],stbmax2[N][30],stbmin2[N][30];

int main() {
    int n,m,q;
    cin >> n >> m >> q;
    lg[1] = 0;
    for (int i = 2;i <= max(n,m);i++) lg[i] = lg[i / 2] + 1; 
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        stmax[i][0] = stmin[i][0] = a[i];
        if (a[i] > 0) stmin2[i][0] = a[i],stmax2[i][0] = -1e9;
        else if (a[i] < 0) stmax2[i][0] = a[i],stmin2[i][0] = 1e9;
    }
    for (int i = 1;i <= m;i++) {
        cin >> b[i];
        stbmax[i][0] = stbmin[i][0] = b[i];
    }
    for (int j = 1;j <= lg[n];j++)
        for (int i = 1;i + (1 << j) - 1 <= n;i++) {
            stmax[i][j] = max(stmax[i][j - 1],stmax[i + (1 << (j - 1))][j - 1]);
            stmin[i][j] = min(stmin[i][j - 1],stmin[i + (1 << (j - 1))][j - 1]);
            stmax2[i][j] = max(stmax2[i][j - 1],stmax2[i + (1 << (j - 1))][j - 1]);
            stmin2[i][j] = min(stmin2[i][j - 1],stmin2[i + (1 << (j - 1))][j - 1]);
        }
    for (int j = 1;j <= lg[m];j++)
        for (int i = 1;i + (1 << j) - 1 <= m;i++) {
            stbmax[i][j] = max(stbmax[i][j - 1],stbmax[i + (1 << (j - 1))][j - 1]);
            stbmin[i][j] = min(stbmin[i][j - 1],stbmin[i + (1 << (j - 1))][j - 1]);
        }
    while (q--) {
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int k1 = lg[r1 - l1 + 1],k2 = lg[r2 - l2 + 1];
        int v1 = max(stmax[l1][k1],stmax[r1 - (1 << k1) + 1][k1]);
        int v2 = min(stmin[l1][k1],stmin[r1 - (1 << k1) + 1][k1]);
        int v3 = min(stmin2[l1][k1],stmin2[r1 - (1 << k1) + 1][k1]);
        int v4 = max(stmax2[l1][k1],stmax2[r1 - (1 << k1) + 1][k1]);
        int maxn = max(stbmax[l2][k2],stbmax[r2 - (1 << k2) + 1][k2]);
        int minn = min(stbmin[l2][k2],stbmin[r2 - (1 << k2) + 1][k2]);
        long long c[] = {v1,v2,v3,v4},ans = -1e18;
        for (int i = 0;i < 4;i++) {
            if (c[i] == -1e9 || c[i] == 1e9) continue;
            ans = max(ans,min(c[i] * maxn,c[i] * minn));
        }
        cout << ans << endl;
    }
    return 0;
}