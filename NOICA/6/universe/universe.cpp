#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

const int K = 1e6 + 5;
int x[K],y[K],m[K],a[1005][1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("universe.in","r",stdin);
    freopen("universe.out","w",stdout);
    int n,k,p;
    cin >> n >> k >> p;
    for (int i = 1;i <= k;i++) {
        cin >> x[i] >> y[i] >> m[i];
        for (int X = 1;X <= n;X++)
            for (int Y = 1;Y <= n;Y++)
                a[X][Y] += max(0,m[i] - max(abs(X - x[i]),abs(Y - y[i])));
    }
    int ans = 0;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            ans += (a[i][j] <= p);
    cout << ans << endl;
    return 0;
}