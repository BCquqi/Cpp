#include<iostream>
using namespace std;

int main() {
    freopen("matching.in","r",stdin);
    freopen("matching.out","w",stdout);
    string s;
    cin >> s;
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        string t;
        cin >> t;
        if (s.size() != t.size()) continue;
        bool flag = true;
        for (int j = 0;j < s.size();j++)
            if (s[j] != '#' && s[j] != t[j]) {flag = false; break;}
        if (flag) ans++;
    }
    cout << ans << endl;
    return 0;
}