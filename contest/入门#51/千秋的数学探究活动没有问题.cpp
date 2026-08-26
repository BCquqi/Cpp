#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1e6 + 5;
int a[N],cur,n,k;
string s;
long long sum = 0;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    while (sum) s = char(sum % 10 + '0') + s, sum /= 10;
    string ans = s;
    int len = s.size();
    for (int i = 1;i <= len;i++) {
        for (int j = i;j <= min(i + k - 1,len);j++) {
            reverse(s.begin() + i - 1,s.begin() + j);
            ans = max(ans,s);
            reverse(s.begin() + i - 1,s.begin() + j);
        }
    }
    cout << ans << endl;
    return 0;
}