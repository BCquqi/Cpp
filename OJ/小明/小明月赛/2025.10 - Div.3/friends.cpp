#include<iostream>
using namespace std;

const int N = 1005;
int x[N];

int count(int x) {
    int res = 0;
    while (x) {
        res += x & 1;
        x >>= 1;
    }
    return res;
}

int main() {
    freopen("friends.in","r",stdin);
    freopen("friends.out","w",stdout);
    int n,m,k,ans = 0;
    cin >> n >> m >> k;
    for (int i = 1;i <= m + 1;i++) cin >> x[i];
    for (int i = 1;i <= m;i++)
        if (count(x[m + 1] ^ x[i]) <= k) ans++;
    cout << ans << endl;
    return 0;
}