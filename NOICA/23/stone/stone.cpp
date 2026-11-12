#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    int pos = upper_bound(a + 1,a + n + 1,n) - a - 1;
    if ((n - pos) & 1) cout << "fengyi" << '\n';
    else cout << "shuji" << '\n';
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}