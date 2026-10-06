#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2.2e7 + 5;
int d[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s = "#";
    char c;
    while (cin >> c) s += c, s += '#';
    int len = s.size();
    for (int i = 0,l = 0,r = -1;i < len;i++) {
        int k = (i > r) ? 1 : min(d[l + r - i],r - i + 1);
        while (0 <= i - k && i + k < len && s[i - k] == s[i + k]) k++;
        d[i] = k--;
        if (i + k > r)
            l = i - k, r = i + k;
    }
    int ans = 0;
    for (int i = 0;i < len;i++) ans = max(ans,d[i] - 1);
    cout << ans << endl;
    return 0;
}