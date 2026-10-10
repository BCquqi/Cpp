#include<iostream>
#define num(x) s[x][r] - s[x][l - 1]
using namespace std;

const int N = 1e5 + 5;
int a[N],s[4][N];

int main() {
    freopen("nan.in","r",stdin);
    freopen("nan.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        s[0][i] = s[0][i - 1], 
        s[1][i] = s[1][i - 1], 
        s[2][i] = s[2][i - 1], 
        s[3][i] = s[3][i - 1];
        s[a[i]][i] = s[a[i]][i - 1] + 1;
    }
    int ans0 = 0,ans1 = 0,ans2 = 0,ans3 = 0;
    for (int len = n;len >= 1;len--)
        for (int l = 1;l + len - 1 <= n;l++) {
            int r = l + len - 1;
            if (num(0) > num(1) && num(0) > num(2) && num(0) > num(3)) ans0 = max(ans0,len);
            else if (num(1) > num(0) && num(1) > num(2) && num(1) > num(3)) ans1 = max(ans1,len);
            else if (num(2) > num(0) && num(2) > num(1) && num(2) > num(3)) ans2 = max(ans2,len);
            else if (num(3) > num(0) && num(3) > num(1) && num(3) > num(2)) ans3 = max(ans3,len);
            if (ans0 && ans1 && ans2 && ans3) continue;
        }
    cout << ans0 << ' ' << ans1 << ' ' << ans2 << ' ' << ans3 << endl;
    return 0;
}