#include<iostream>
#include<algorithm>
using namespace std;

const int P = 131,mod = 1e9 + 7,N = 5e5 + 5;
long long p[N],h[N];

long long Hash(int l,int r) {return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;}

int main() {
    int n,q;
    string s;
    cin >> n >> s >> q;
    s = ' ' + s;
    p[0] = 1;
    for (int i = 1;i <= n;i++) {
        p[i] = p[i - 1] * P % mod;
        h[i] = (h[i - 1] * P + s[i]) % mod;
    }
    while (q--) {
        int a,b,ans = 1e9;
        cin >> a >> b;
        for (int l = 1;l * l <= b - a + 1;l++) {
            if ((b - a + 1) % l != 0) continue;
            if (Hash(a,b - l) == Hash(l + a,b)) {
                ans = l;
                break;
            }
            if (Hash(a,b - (b - a + 1) / l) == Hash((b - a + 1) / l + a,b))
                ans = min(ans,(b - a + 1) / l);
        }
        cout << ans << endl;
    }
    return 0;
}