#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
    freopen("coloring.in","r",stdin);
    freopen("coloring.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    int ans = 1e9;
    for (int i = 0;i <= n + 1;i++)
        ans = min(ans,max((i == 0) ? 0 : a[i - 1] - 1,(i == n + 1) ? 0 : 1000000 - a[i]));
    cout << ans << endl;
    return 0;
}