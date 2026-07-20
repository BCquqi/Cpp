#include<iostream>
#include<map>
using namespace std;

const int N = 2e6 + 5;
int a[N];

map<int,int> mp;

int main() {
    freopen("wait.in","r",stdin);
    freopen("wait.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,ans = 0;
    string s;
    cin >> n >> s;
    s = '?' + s;
    a[0] = 0,mp[0] = 0;
    for (int i = 1;i <= n;i++) {
        if (s[i] == 'l') a[i] = a[i - 1] + 1;
        else a[i] = a[i - 1] - 1;
        if (mp.find(a[i]) == mp.end()) mp[a[i]] = i;
        else ans = max(ans,i - mp[a[i]]);
    }
    cout << ans << endl;
    return 0;
}