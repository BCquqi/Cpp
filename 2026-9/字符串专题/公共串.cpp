#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;

const int N = 10, M = 2005, mod = 1e9 + 7, P = 129;
int n, maxlen = 0, maxid = 0;
string s[N];
ll hs[N][M], power[M];
unordered_map<int,bool> mp[N];

inline ll Hash(int id, int l,int r)
{return (hs[id][r] - hs[id][l - 1] * power[r - l + 1] % mod + mod) % mod;}

bool check (int mid) {
    for (int i = 1; i <= n; i++) mp[i].clear();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j + mid - 1 <= s[i].size(); j++)
            mp[i][Hash(i,j,j + mid - 1)] = true;
    for (int i = 1; i + mid - 1 <= maxlen; i++) {
        int range = Hash(maxid, i, i + mid - 1);
        bool flag = true;
        for (int j = 1;j <= n;j++) flag &= mp[j][range];
        if (flag) return true;
    }
    return false;
}

int main() {
    cin >> n;
    power[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        if (s[i].size() > maxlen)
            maxlen = s[i].size(), maxid = i;
        s[i] = '?' + s[i];
        hs[i][0] = 0;
        for (int j = 1; j < s[i].size(); j++)
            hs[i][j] = (hs[i][j - 1] * P % mod + s[i][j]) % mod;
    }
    for (int i = 1; i <= maxlen; i++)
        power[i] = (power[i - 1] * P) % mod;
    int l = 0, r = maxlen, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}