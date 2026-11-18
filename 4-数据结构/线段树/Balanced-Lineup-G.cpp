#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5e4 + 5;
int h[N],lg[N],stmax[N][30],stmin[N][30];

int main() {
    int n,q;
    cin >> n >> q;
    for (int i = 1;i <= n;i++) cin >> h[i];
    lg[1] = 0;
    for (int i = 2;i <= n;i++) lg[i] = lg[i / 2] + 1;
    for (int i = 1;i <= n;i++) stmax[i][0] = stmin[i][0] = h[i];
    for (int j = 1;j <= lg[n];j++)
        for (int i = 1;i + (1 << j) - 1 <= n;i++)
            stmax[i][j] = max(stmax[i][j - 1],stmax[i + (1 << (j - 1))][j - 1]),
            stmin[i][j] = min(stmin[i][j - 1],stmin[i + (1 << (j - 1))][j - 1]);
    while (q--) {
        int a,b;
        cin >> a >> b;
        int k = lg[b - a + 1];
        cout << max(stmax[a][k],stmax[b - (1 << k) + 1][k]) - min(stmin[a][k],stmin[b - (1 << k) + 1][k]) << endl;
    }
    return 0;
}