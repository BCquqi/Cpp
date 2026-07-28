#include<iostream>
#include<cstring>
using namespace std;

const int N = 12;
int h,w;
long long dp[N][1 << N];

bool check(int x) {
    int cnt = 0;
    for (int i = 1;i <= w;i++) {
        if (!(x & 1)) cnt++;
        else {
            if (cnt & 1) return false;
            cnt = 0;
        }
        x >>= 1;
    }
    if (cnt & 1) return false;
    return true;
}

int main() {
    while (cin >> h >> w) {
        if (h == 0 && w == 0) break;
        memset(dp,0,sizeof dp);
        for (int i = 0;i < (1 << w);i++)
            if (check(i)) dp[1][i] = 1;
        for (int i = 2;i <= h;i++)
            for (int j = 0;j < (1 << w);j++)
                for (int k = 0;k < (1 << w);k++)
                    if (((j & k) == 0) && check(j | k)) dp[i][j] += dp[i - 1][k];
        cout << dp[h][0] << endl;
    }
    return 0;
}