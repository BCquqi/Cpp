#include<iostream>
#include<cmath>
using namespace std;

const int N = 1e5 + 5;
int t[N];
string op[N];

int main() {
    int n,m;
    long long ans = 0,s = 0;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> op[i] >> t[i];
    for (int i = 30;i >= 0;i--) {
        bool flag1 = true,flag2 = false;
        for (int j = 1;j <= n;j++) {
            bool tmp = (t[j] >> i) & 1;
            if (op[j] == "AND") flag1 &= tmp,flag2 &= tmp;
            else if (op[j] == "OR") flag1 |= tmp,flag2 |= tmp;
            else flag1 ^= tmp,flag2 ^= tmp;
        }
        if (flag2) ans |= (1 << i);
        else if (flag1 && (s | (1 << i)) <= m)
            s |= 1 << i,ans |= 1 << i;
    }
    cout << ans << endl;
    return 0;
}