#include<iostream>
using namespace std;

const int N = 1005;
string a[N];

int main() {
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,cnt = 1,ans = 0;
    cin >> n;
    a[0] = "";
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if (a[i] == a[i - 1]) cnt++;
        else cnt = 1;
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}