#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 5e5 + 5;
int a[N],s[N];
bool dp[N];
// dp[i]表示: 1-i 能否满足要求

void solve() {
    int n,k,d;
    cin >> n >> k >> d;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    memset(dp,false,sizeof dp);
    dp[0] = true;
    int left = 1;
    s[1] = 1;
    for (int i = 1;i <= n;i++) {
        while (left < i && a[i] - a[left] > d) left++;
        int L = left - 1, R = i - k;
        // [L,R] 上一个盒子的结尾所在范围
        if (L <= R)
            if (s[R + 1] - s[L]) dp[i] = true;
        s[i + 1] = s[i] + (dp[i] == true);
    }
    cout << (dp[n] ? "YES" : "NO") << endl;
    return ;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}