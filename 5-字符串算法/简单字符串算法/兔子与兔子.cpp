#include<iostream>
using namespace std;

const int N = 1e6 + 5,P = 131,mod = 1e9 + 7;
long long hs[N],powP[N];

int main() {
    string s;
    cin >> s;
    s = '?' + s;
    powP[0] = 1;
    for (int i = 1;i < s.size();i++)
        hs[i] = (hs[i - 1] * P % mod + s[i]) % mod, powP[i] = powP[i - 1] * P % mod;
    int m;
    cin >> m;
    while (m--) {
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if ((hs[r1] - hs[l1 - 1] * powP[r1 - l1 + 1] % mod + mod) % mod == (hs[r2] - hs[l2 - 1] * powP[r2 - l2 + 1] % mod + mod) % mod) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}