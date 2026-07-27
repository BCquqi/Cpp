#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2505;
struct Range {int l,r;} s[N];
struct Node {int spf,cover;} a[N];

// 区间覆盖板子

int main() {
    int c,l,ans = 0;
    cin >> c >> l;
    for (int i = 1;i <= c;i++) cin >> s[i].l >> s[i].r;
    for (int i = 1;i <= l;i++) cin >> a[i].spf >> a[i].cover;
    sort(s + 1,s + c + 1,[](Range x,Range y) {return x.r < y.r;});
    sort(a + 1,a + l + 1,[](Node x,Node y) {return x.spf < y.spf;});
    for (int i = 1;i <= c;i++) // 奶牛
        for (int j = 1;j <= l;j++) // 霜
            if (a[j].spf >= s[i].l && a[j].spf <= s[i].r && a[j].cover > 0) {
                ans++,a[j].cover--;
                break;
            }
    cout << ans << endl;
    return 0;
}