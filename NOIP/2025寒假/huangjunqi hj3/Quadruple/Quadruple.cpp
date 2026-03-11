#include<iostream>
using namespace std;

int n,k;

int calc(int num) {return min(num - 1,2 * n + 1 - num);}

int main() {
    cin >> n >> k;
    k = k < 0 ? -k : k;
    long long ans = 0;
    for (int j = 2;j <= 2 * n - k;j++) {
        int i = j + k;
        ans += 1ll * calc(i) * calc(j);
    }
    cout << ans << endl;
    return 0;
} 