#include<iostream>
using namespace std;

int main() {
    freopen("maxscale.in","r",stdin);
    freopen("maxscale.out","w",stdout);
    // 二分答案求 [l,r] 范围内两数的最大公约数最大值
    int l,r;
    cin >> l >> r;
    for (int i = r - l;i >= 1;i--)
        if (r / i - (l - 1) / i >= 2) {
            cout << i << endl;
            return 0;
        }
    return 0;
}