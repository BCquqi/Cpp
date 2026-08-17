#include<iostream>
using namespace std;

const int N = 1e5 + 5,M = 1e4 + 5;
int s[N],a[N],dp[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> s[i];
        
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= i;j++) a[j] = a[j - 1] + (s[j] == s[i]);
        for (int j = 1;j <= i;j++) // 朴素
            dp[i] = max(dp[i],dp[j - 1] + s[i] * a[i] * s[i] + s[i] * (a[j] - 1) * (a[j] - 1) - 2 * s[i] * a[i] * a[j]);
    }
    return 0;
}