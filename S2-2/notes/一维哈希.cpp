p[0] = 1;
for (int i = 1;i <= n;i++) {
    p[i] = p[i - 1] * P % mod;
    hs[i] = (hs[i - 1] * P + s[i]) % mod;
}

long long Hash(int l,int r) {return (hs[r] - hs[l - 1] * p[r - l + 1] % mod + mod) % mod;}