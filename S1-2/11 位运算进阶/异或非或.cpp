#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

const int N = 5e5 + 5;
int dp[N],n,m;
long long a[N],s[N];

bool check(long long tmp) {
    if ((s[n] & tmp) != 0) return false;
    memset(dp,0,sizeof dp);
    unordered_map<long long,int> mp;
    mp[s[0] & tmp] = 0;
    for (int i = 1;i <= n;i++) {
        long long target = s[i] & tmp;
        if (mp.count(target))
            dp[i] = mp[target] + 1;
        if (dp[i] > 0) mp[target] = max(dp[i],mp[target]);
    }
    return dp[n] >= m;
}

int main() {
    long long ans = 0,mask = 0;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
    }
    for (int k = 62;k >= 0;k--) {
        long long tmp = mask | (1ll << k);
        if (check(tmp)) mask = tmp;
        else ans |= (1ll << k);
    }
    cout << ans << endl;
    return 0;
}