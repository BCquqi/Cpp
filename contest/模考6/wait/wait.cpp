#include<iostream>
#include<map>
#include<cstring>
using namespace std;

const int N = 2e6 + 5;
int a[N],mp[2 * N];

int main() {
    freopen("wait.in","r",stdin);
    freopen("wait.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,ans = 0;
    string s;
    cin >> n >> s;
    s = '?' + s;
    memset(mp,-1,sizeof mp); // 必须 memset 避免存在和第一个是 0 搞混
    a[0] = 0,mp[N] = 0;
    for (int i = 1;i <= n;i++) {
        if (s[i] == 'l') a[i] = a[i - 1] + 1;
        else a[i] = a[i - 1] - 1;
        if (mp[a[i] + N] == -1) mp[a[i] + N] = i;
        else ans = max(ans,i - mp[a[i] + N]);
    }
    cout << ans << '\n';
    return 0;
}