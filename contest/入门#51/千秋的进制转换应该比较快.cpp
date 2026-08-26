#include<iostream>
using namespace std;

string mp[16] = {
    "0000","0001","0010","0011",
    "0100","0101","0110","0111",
    "1000","1001","1010","1011",
    "1100","1101","1110","1111"
};

inline string change(char c) {
    if ('0' <= c && c <= '9') return mp[c - '0'];
    else return mp[c - 'A' + 10];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cur = 0;
    while (s[cur] == '0') cur++;
    if (cur == s.size()) {
        cout << 0 << endl;
        return 0;
    }
    s = s.substr(cur,s.size() - cur); 
    string ans = "";
    for (int i = 0;i < s.size();i++)
        ans += change(s[i]);
    cur = 0;
    while (ans[cur] == '0') cur++;
    cout << ans.substr(cur,ans.size() - cur) << endl;
    return 0;
}