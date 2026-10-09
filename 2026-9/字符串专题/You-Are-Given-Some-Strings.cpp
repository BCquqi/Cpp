#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5 + 5,B = 450;
const ull P = 131;
string t,s[N];
int n,m;
ull power[N],hs[N];
ll last[N],first[N];
int lenArr[N],lenCnt = 0;
gp_hash_table<ull,int> mp;

ull Hash(int l,int r) {return hs[r + 1] - hs[l] * power[r - l + 1];}

void init() {
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
    for (int i = 1;i <= n;i++) if (s[i].size() <= B) {
        ull h = 0;
        for (int j = 0;j < s[i].size();j++) h = h * P + s[i][j];
        mp[h]++, lenArr[lenCnt++] = s[i].size();
    }
    sort(lenArr,lenArr + lenCnt);
    lenCnt = unique(lenArr,lenArr + lenCnt) - lenArr;
    for (int i = 0;i < m;i++)
        for (int k = 0;k < lenCnt;k++) {
            int L = lenArr[k];
            if (L > i + 1) break;
            auto it = mp.find(Hash(i - L + 1,i));
            if (it != mp.end()) last[i] += it->second;
        }
    for (int i = 0;i < m;i++)
        for (int k = 0;k < lenCnt;k++) {
            int L = lenArr[k];
            if (i + L - 1 >= m) break;
            auto it = mp.find(Hash(i,i + L - 1));
            if (it != mp.end()) first[i] += it->second;
        }
    for (int i = 1;i <= n;i++) if (s[i].size() > B) {
        int L = s[i].size();
        ull h = 0;
        for (int j = 0;j < L;j++) h = h * P + s[i][j];
        for (int j = 0;j + L - 1 < m;j++)
            if (Hash(j,j + L - 1) == h) last[j + L - 1]++, first[j]++;
    }
    ll ans = 0;
    for (int i = 0;i < m - 1;i++) ans += last[i] * first[i + 1];
    cout << ans << '\n';
    return 0;
}