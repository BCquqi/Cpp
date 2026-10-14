#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 2e5 + 5;
int a[2][N];

void solve() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[0][i];
    for (int i = 1;i <= n;i++) cin >> a[1][i];
    
    int ans = 0;
    
    // 单行情况
    for (int i = 0;i < 2;i++) {
        int cur = 0,maxL = 0;
        for (int j = 1;j <= n;j++) {
            if (a[i][j] == 1) cur++;
            else cur = 0;
            maxL = max(maxL,cur);
        }
        ans = max(ans,maxL - 2 * min(m,maxL));
    }
    
    // 双行情况
    int curA = 0,maxA = 0;
    for (int j = 1;j <= n;j++) {
        if (a[0][j] == 0 && a[1][j] == 0) curA = 0;
        else {
            if (a[0][j] == 1 && a[1][j] == 1) curA++;
            maxA = max(maxA,curA);
        }
    }
    ans = max(ans,2 * (maxA - min(m,maxA)));
    
    cout << ans << endl;
}

int main() {
    int sub,T;
    cin >> sub >> T;
    while (T--) solve();
    return 0;
}