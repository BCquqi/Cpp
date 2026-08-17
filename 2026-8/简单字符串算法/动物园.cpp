#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e6 + 5,mod = 1e9 + 7;
int prefix[N],ans[N];

long long solve(string s) {
    memset(prefix,0,sizeof prefix);
    memset(ans,0,sizeof ans);
    ans[1] = 1;
    long long ret = 1;
    int len = s.size();
    for (int i = 1;i < len;i++) {
        int j = prefix[i];
        while (j > 0 && s[i] != s[j]) j = prefix[j];
        if (s[i] == s[j]) j++;
        prefix[i + 1] = j, ans[i + 1] = ans[j] + 1;
    }
    int j = 0;
    for (int i = 1;i < len;i++) {
        while (j > 0 && s[i] != s[j]) j = prefix[j];
        if (s[i] == s[j]) j++;
        while (j * 2 > i + 1) j = prefix[j];
        ret = ret * (ans[j] + 1) % mod;
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}