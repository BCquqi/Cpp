#include<iostream>
using namespace std;

int cnt[30];

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    cin >> s;
    for (int i = 0;i < s.size();i++) cnt[s[i] - 'a' + 1]++,cnt[s[i] - 'a' + 1] %= 2;
    bool ans = true;
    for (int i = 1;i <= 26;i++) ans &= (!cnt[i]);
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}