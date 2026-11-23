#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e6 + 5;
int prefix[N];

void solve(string s) {
    int len = s.size();
    for (int i = 1;i < len;i++) {
        int j = prefix[i - 1];
        while (j > 0 && s[i] != s[j]) j = prefix[j - 1];
        if (s[i] == s[j]) j++;
        prefix[i] = j;
    }
    return ;
}

int main() {
    int n;
    cin >> n;
    string ans = "";
    for (int i = 1;i <= n;i++) {
        string s;
        cin >> s;
        string t = s + '#' + ans.substr(ans.size() - min(s.size(),ans.size()),min(s.size(),ans.size()));
        solve(t);
        for (int j = prefix[t.size() - 1];j < s.size();j++) ans += s[j];
    }
    cout << ans << endl;
    return 0;
}