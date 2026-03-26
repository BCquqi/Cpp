#include<iostream>
#include<cmath>
using namespace std;

const int N = 2005;
int a[N];

int main() {
    int n,z,w;
    cin >> n >> z >> w;
    for (int i = 1;i <= n;i++) cin >> a[i];
    if (n == 1) cout << abs(w - a[1]) << endl;
    else {
        int ans1 = abs(a[n - 1] - a[n]);
        int ans2 = abs(a[n] - w);
        cout << max(ans1,ans2) << endl;
    }
    return 0;
}

// https://atcoder.jp/contests/arc085/submissions/74024135