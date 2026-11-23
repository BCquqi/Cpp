#include<iostream>
#include<algorithm>
using namespace std;

const int N = 305;
int dp[2][N][N][N];

int main() {
    freopen("horse.in","r",stdin);
    freopen("horse.out","w",stdout);
    int n,m,c1,c2,c3,ans = 0;
    cin >> n >> m;
    cin >> c1 >> c2 >> c3;
    ans += min(c3,3 * n);
    c3 -= ans;
    for (int i = 1;i <= n;i++)
        if (c2 >= 4 && c3 >= 1) c3--, c2 -= 4, ans += 5;
        else if (c2 >= 3 && c3 >= 2) c2 -= 3, c3 -= 2, ans += 5;
        else if (c2 >= 2 && c3 >= 2) c2 -= 2, c3 -= 2, ans += 4;
        else if (c2 >= 2 && c1 >= 1) c2 -= 2, c1--, ans += 3;
        else if (c2 >= 1 && c1 >= 1) c1--, c2--, ans += 2;
        else if (c1 >= 1) c1--, ans++;
    cout << ans << endl;
    return 0;
}