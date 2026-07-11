#include<iostream>
using namespace std;

const int N = 5e6 + 5;
int a[N],diff[N];

int main() {
    int n,p,ans = 1e9,sum = 0;
    cin >> n >> p;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        diff[i] = a[i] - a[i - 1];
    }
    for (int i = 1;i <= n;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        diff[x] += z,diff[y + 1] -= z;
    }
    for (int i = 1;i <= n;i++) {
        sum += diff[i];
        ans = min(ans,sum);
    }
    cout << ans << endl;
    return 0;
}