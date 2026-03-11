#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int a[N],sum[N];

int main() {
    int n,m;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    cin >> m;
    while (m--) {
        int l,r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}