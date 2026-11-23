#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e4 + 5,mod = 1e9 + 7,P = 129;
string s[N];
int hs[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> s[i];
        hs[i] = s[i][0];
        for (int j = 1;j < s[i].size();j++)
            hs[i] = (hs[i] * P % mod + s[i][j]) % mod;
    }
    sort(hs + 1,hs + n + 1);
    int ans = unique(hs + 1,hs + n + 1) - hs - 1;
    cout << ans << endl;
    return 0;
}