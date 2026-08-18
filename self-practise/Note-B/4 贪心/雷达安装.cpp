#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

const int N = 1e3 + 5;
struct Node {double l,r; bool vis;} a[N];
// 岛搜索雷达

int main() {
    int n,d,ans = 0;
    cin >> n >> d;
    for (int i = 1;i <= n;i++) {
        int x,y;
        cin >> x >> y;
        if (y > d) {
            cout << -1 << endl;
            return 0;
        }
        double tmp = sqrt(1.0 * d * d - 1.0 * y * y);
        a[i].l = x - tmp,a[i].r = x + tmp;
    }
    sort(a + 1,a + n + 1,[](Node x,Node y) {return x.r < y.r;});
    for (int i = 1;i <= n;i++) {
        if (a[i].vis) continue;
        a[i].vis = true,ans++;
        for (int j = 1;j <= n;j++)
            if (a[i].r >= a[j].l) a[j].vis = true;
    }
    cout << ans << endl;
    return 0;
}