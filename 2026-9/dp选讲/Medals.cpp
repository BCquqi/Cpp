#include <iostream>
using namespace std;

const int N = 20;
int a[N];

bool check(int mid) {
    
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n;i++) cin >> a[i];
    int l = 1, r = 2 * n * k,ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
        cout << ans << endl;
    }
    return 0;
}