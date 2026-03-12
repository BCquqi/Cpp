#include<iostream>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int ans = (1 << m) * ((n - m) * 100 + m * 1900);
    cout << ans << endl;
    return 0;
}

// https://atcoder.jp/contests/arc085/submissions/74014736