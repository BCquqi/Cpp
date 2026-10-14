#include<iostream>
#include<unordered_set>
using namespace std;

const int N = 55,P = 53,Q = 59;
int a[N][N],b[N][N];
unsigned long long p[N],q[N],ha[N][N],hb[N][N];
unordered_set<unsigned long long> s;

unsigned long long Hash(unsigned long long h[N][N],int x1,int y1,int x2,int y2) {
    unsigned long long ret = h[x2][y2] - h[x1 - 1][y2] * p[x2 - x1 + 1] - h[x2][y1 - 1] * q[y2 - y1 + 1]
     + h[x1 - 1][y1 - 1] * p[x2 - x1 + 1] * q[y2 - y1 + 1];
     return ret;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) cin >> a[i][j];
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) cin >> b[i][j];
    p[0] = q[0] = 1;
    for (int i = 1;i <= n;i++) p[i] = p[i - 1] * P,q[i] = q[i - 1] * Q;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            ha[i][j] = ((ha[i - 1][j] * P + ha[i][j - 1] * Q - ha[i - 1][j - 1] * P * Q + a[i][j]));
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            hb[i][j] = ((hb[i - 1][j] * P + hb[i][j - 1] * Q - hb[i - 1][j - 1] * P * Q + b[i][j]));
    int ans = 0;
    for (int i = 1;i <= n;i++) 
        for (int j = 1;j <= n;j++)
            for (int k = min(n - i + 1, n - j + 1);k >= 1;k--)
                s.insert(Hash(ha,i,j,i + k - 1,j + k - 1));
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            for (int k = min(n - i + 1, n - j + 1);k >= 1;k--)
                if (s.find(Hash(hb,i,j,i + k - 1,j + k - 1)) != s.end()) {
                    ans = max(ans,k);
                    break;
                }
    cout << ans << endl;
    return 0;
}