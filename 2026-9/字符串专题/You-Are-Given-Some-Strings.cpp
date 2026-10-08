#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5 + 5,B = 85;
string t,s[N];
int n,m;
ull P,power[N],hs[N],vis[N];
ll b[N],ans;
unordered_map<ull,int> mp;

ull Hash(int l,int r) {return hs[r + 1] - hs[l] * power[r - l + 1];}

void init() {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    P = rng() | 1;               // 保证奇数
    if (P < (1ull << 40)) P += (1ull << 40);  // 避免过小
    power[0] = 1;
    for (int i = 1;i < N;i++) power[i] = power[i - 1] * P;
    m = t.size(), hs[0] = 0;
    for (int i = 0;i < m;i++) hs[i + 1] = hs[i] * P + t[i];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t >> n;
    for (int i = 1;i <= n;i++) cin >> s[i];
    init();
    for (int i = 1;i <= n;i++) if (s[i].size() > B) {
        int L = s[i].size();
        ull h = 0;
        for (char c : s[i]) h = h * P + c;
        vis[i] = h;
        for (int j = 0;j + L <= m;j++)
            if (Hash(j,j + L - 1) == h) b[j]++;
    }
    for (int i = 1;i <= n;i++) if (s[i].size() <= B) {
        ull h = 0;
        for (char c : s[i]) h = h * P + c;
        mp[h]++;
    }
    for (int i = m - 1;i >= 0;i--)
        for (int L = 1;L <= B && i + L <= m;L++) {
            auto it = mp.find(Hash(i,i + L - 1));
            if (it != mp.end()) b[i] += it->second, ans += 1LL * it->second * b[i + L];
        }
    for (int i = 1;i <= n;i++) if (s[i].size() > B) {
        int L = s[i].size();
        for (int j = 0;j + L <= m;j++)
            if (Hash(j,j + L - 1) == vis[i]) ans += b[j + L];
    }
    cout << ans << '\n';
    return 0;
}