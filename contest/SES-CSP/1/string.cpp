#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e3 + 5,mod = 1e9 + 7;
string s[N];
int a[N];
long long dp[N],c[N][N];

long long C(int n,int m) {
    if (c[n][m] != 0) return c[n][m];
    if (n == m || n == 0 || m == 0) return c[n][m] = 1;
    return c[n][m] = (C(n - 1,m - 1) + C(n - 1,m)) % mod;
}

int main() {
    // freopen("string.in","r",stdin);
    // freopen("string.out","w",stdout);
    int n,k,cur = 0;
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> s[i];
        sort(s[i].begin(),s[i].end());
    }
    sort(s + 1,s + n + 1);
    for (int i = 1;i <= n;i++)
        if (s[i] != s[i - 1]) a[++cur]++;
        else a[cur]++;
    dp[0] = 1;
    for (int i = 1;i <= cur;i++)
        for (int j = k;j >= 0;j--)
            for (int x = 1;x <= a[i] &&  x * (x - 1) / 2 <= j;x++)
                dp[j] = (dp[j] + dp[j - x * (x - 1) / 2] * C(a[i],x) % mod) % mod;
    cout << dp[k] << endl;
    return 0;
}