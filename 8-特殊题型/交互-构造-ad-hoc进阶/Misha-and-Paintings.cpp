#include<iostream>
#include<cstring>
using namespace std;

const int N = 505,NN = N * N;
int a[N][N];
int mxr[NN],mnr[NN],mxc[NN],mnc[NN];
bool flag[NN];
int diff[N][N];

int main() {
    int n,k;
    cin >> n >> k;
    memset(mxr,0,sizeof mxr);
    memset(mnr,0x3f,sizeof mnr);
    memset(mxc,0,sizeof mxc);
    memset(mnc,0x3f,sizeof mnc);
    int m = 0;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) {
            cin >> a[i][j];
            if (flag[a[i][j]] == false) m++;
            flag[a[i][j]] = true;
            mxr[a[i][j]] = max(mxr[a[i][j]],i), 
            mnr[a[i][j]] = min(mnr[a[i][j]],i), 
            mxc[a[i][j]] = max(mxc[a[i][j]],j), 
            mnc[a[i][j]] = min(mnc[a[i][j]],j);
        }
    if (m <= k) {
        cout << k - m << endl;
        return 0;
    }
    for (int len = 1;len <= n;len++) {
        memset(diff,0,sizeof diff);
        for (int color = 0;color < NN;color++) {
            if (!flag[color]) continue;
            int r1 = max(1,mxr[color] - len + 1);
            int r2 = min(mnr[color],n - len + 1);
            int c1 = max(1,mxc[color] - len + 1);
            int c2 = min(mnc[color],n - len + 1);
            if (r1 > r2 || c1 > c2) continue;
            diff[r1][c1]++;
            diff[r2 + 1][c1]--;
            diff[r1][c2 + 1]--;
            diff[r2 + 1][c2 + 1]++;
        }
        for (int i = 1;i <= n - len + 1;i++)
            for (int j = 1;j <= n - len + 1;j++) {
                diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
                if (m - diff[i][j] == k || m - diff[i][j] == k - 1) {
                    cout << 1 << endl;
                    return 0;
                }
            }
    }
    cout << 2 << endl;
    return 0;
}