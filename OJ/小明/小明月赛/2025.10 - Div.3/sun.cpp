#include<iostream>
#include<cstring>
using namespace std;

const int N = 2e5 + 5;
int a[N];

int main() {
    freopen("sun.in","r",stdin);
    freopen("sun.out","w",stdout);
    int t;
    cin >> t;
    while (t--) {
        memset(a,0,sizeof a);
        int k,cur = 0,ans = 0;
        string s;
        cin >> k >> s;
        int n = s.size();
        for (int i = 0;i < n;i++) {
            if (s[i] == '0') {
                a[cur]++;
                if (i == n - 1) cur++;
            }
            else if (i > 0 && s[i - 1] == '0') cur++;
        }
        if (!cur) ans = 0;
        else if (cur == 1 && a[0] == n) ans = (n + k) / (k + 1);
        else {
            if (s[0] == '0') {
                if (a[0] > k) ans = a[0] / (k + 1);
                a[0] = 0;
            }
            if (s[n - 1] == '0') {
                if (a[cur - 1] > k) ans += a[cur - 1] / (k + 1);
                a[cur - 1] = 0;
            }
            for (int i = 0;i < cur;i++)
                if (a[i] > 2 * k) ans += (a[i] - k) / (k + 1);
        }
        cout << ans << endl;
    }
    return 0;
}