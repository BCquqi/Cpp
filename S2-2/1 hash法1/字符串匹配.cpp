#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int P = 131,mod = 1e9 + 7,N = 1e6 + 5;
long long p[N],hs[N];

long long Hash(int l,int r) {return (hs[r] - hs[l - 1] * p[r - l + 1] % mod + mod) % mod;}

int main() {
    string s,t;
    cin >> s >> t;
    int n = s.size(),m = t.size();
    s = ' ' + s,t = ' ' + t;
    p[0] = 1;
    for (int i = 1;i <= n;i++) {
        p[i] = p[i - 1] * P % mod;
        hs[i] = (hs[i - 1] * P + s[i]) % mod;
    }
    long long ht = 0;
    for (int i = 1;i <= m;i++) ht = (ht * P + t[i]) % mod;
    int ans = 0;
    for (int i = 1;i + m - 1 <= n;i++) {
        int x = Hash(i,i + m - 1);
        if (x == ht) ans++;
    }
    cout << ans << endl;
    return 0;
}