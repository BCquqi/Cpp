#include<iostream>
using namespace std;

const int N = 2e5 + 5;
int n,k,ans = 0,a[N];

bool check(int x) {
    int cnt = 0,tmp = 0;
    for (int i = 1;i <= n + 1;i++) {
        tmp |= a[i];
        if ((tmp & x) == x) cnt++,tmp = 0; // 重要! & 优先级小于 == !
    }
    return cnt >= k;
}

int main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) cin >> a[i];
    k = n - k; // 最多可以分成 n - k 段
    for (int i = 30;i >= 0;i--) // 枚举对应位数为 1 是否可行
        if (check(ans + (1 << i))) ans += 1 << i;
    cout << ans << endl;
    return 0;
}