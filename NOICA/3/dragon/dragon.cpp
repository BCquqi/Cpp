#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 3e5 + 5;
struct Node {int atk,d,id;} a[N];
int s[N];

signed main() {
    freopen("dragon.in","r",stdin);
    freopen("dragon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,h;
    cin >> n >> h;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].atk >> a[i].d;
        a[i].id = i;
    }
    sort(a + 1,a + n + 1,[](Node x,Node y) {return x.atk - x.d > y.atk - y.d;});
    int top = n;
    while (top > 0 && a[top].atk - a[top].d <= 0) top--; // 剔除负面效果
    for (int i = 1;i <= top;i++)
        s[i] = s[i - 1] + a[i].atk - a[i].d;
    int ans = 1e18;
    for (int i = 1;i <= n;i++) { // 枚举绝杀头
        int attack = h - a[i].atk;
        if (a[i].atk >= h) {
            cout << "YES" << endl << 1 << endl;
            return 0;
        }
        int pos = lower_bound(s + 1,s + top + 1,attack) - s;
        if (pos == top + 1) continue; // 特判无法解决
        if (i > pos) ans = min(ans,pos + 1); // 绝杀头不在使用者之中
        else {
            int pos2 = lower_bound(s + 1,s + top + 1,attack + a[i].atk - a[i].d) - s;
            if (pos2 <= top) ans = min(ans, pos2);
        }
    }
    if (ans == 1e18) cout << "NO" << endl;
    else cout << "YES" << endl << ans << endl;
    return 0;
}