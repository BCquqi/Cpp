#include<iostream>
using namespace std;

const int N = 1005;
int a[N],b[N],e[N],f[N],c[N],d[N];

int main() {
    int n,m1,m2;
    cin >> n >> m1 >> m2;
    for (int i = 1;i <= m1;i++) cin >> a[i], e[i] = a[i];
    for (int i = 1;i <= m2;i++) cin >> b[i], f[i] = b[i];
    for (int i = 1;i <= n;i++) {
        c[i] = d[i] = 1e9;
        int cur1 = 0,cur2 = 0;
        for (int j = 1;j <= m1;j++)
            if (e[j] < c[i]) cur1 = j, c[i] = e[j];
        for (int j = 1;j <= m2;j++)
            if (f[j] < d[i]) cur2 = j, d[i] = f[j];
        e[cur1] += a[cur1], f[cur2] += b[cur2];
    }
    int ans = 0;
    for (int i = 1;i <= n;i++) ans = max(ans,c[i] + d[n - i + 1]);
    cout << c[n] << ' ' << ans << endl;
    return 0;
}