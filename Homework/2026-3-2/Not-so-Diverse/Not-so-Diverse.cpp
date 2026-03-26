#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e5 + 5;
int a[N],box[N];

int main() {
    int n,k,ans = 0;
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        box[a[i]]++;
    }
    sort(box + 1,box + n + 1);
    for (int i = 1;i <= n - k;i++) ans += box[i];
    cout << ans << endl;
    return 0;
}

// https://atcoder.jp/contests/arc086/submissions/74024570