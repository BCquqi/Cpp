#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int a[N],pos[N];
bool dp[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = n - 1;i >= 1;i--)
        for (int j = 0;i * j + pos[i] % i <= n;j++)
            if (a[i * j + pos[i] % i] > i) dp[i] |= !dp[a[i * j + pos[i] % i]];
    for (int i = 1;i <= n;i++) {
        if (dp[a[i]]) cout << 'A';
        else cout << 'B';
    }
    cout << endl;
    return 0;
}