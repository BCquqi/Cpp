#include<iostream>
using namespace std;

const int N = 405;
int x[N],y[N];

int main() {
    int n,m,ans = 0;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) cin >> x[i] >> y[i];
    for (int i = 0;i <= (1 << n) - 1;i++) {
        bool flag = true;
        for (int j = 1;j <= m;j++)
            if (((i >> (x[j] - 1)) & 1) && ((i >> (y[j] - 1)) & 1)) {flag = false; break;}
        ans += flag;
    }
    cout << ans << endl;
    return 0;
}