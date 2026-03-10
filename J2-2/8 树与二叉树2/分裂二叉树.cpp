#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5e4 + 5;
int s[N],a[N],l[N],r[N];

void last_search(int u) {
    if (l[u]) last_search(l[u]);
    if (r[u]) last_search(r[u]);
    s[u] = s[l[u]] + s[r[u]] + a[u];
    return ;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) cin >> l[i] >> r[i];
    last_search(1);
    long long ans = 0;
    for (int i = 2;i <= n;i++) ans = max(ans,1ll * s[i] * (s[1] - s[i]));
    cout << ans << endl;
    return 0;
}