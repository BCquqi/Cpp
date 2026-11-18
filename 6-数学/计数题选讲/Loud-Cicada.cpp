#include<iostream>
#define int long long
using namespace std;

const int N = 25;
int a[N];
int n,m,y;
__int128 C[N][N],ans;

inline int gcd(int x,int y) {return y ? gcd(y,x % y) : x;}

void init() {
    C[0][0] = 1;
    for (int i = 1;i <= n;i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1;j < i;j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    return ;
}

void print(__int128 x) {
    if (x == 0) {
        cout << 0 << endl;
        return ;
    }
    char s[50];
    int len = 0;
    while (x) s[++len] = '0' + (int)(x % 10),x /= 10;
    for (int i = len;i >= 1;i--) cout << s[i];
    cout << endl;
    return ;
}

signed main() {
    cin >> n >> m >> y;
    for (int i = 1;i <= n;i++) cin >> a[i];
    init();
    for (int mask = 1;mask < (1 << n);mask++) {
        int cnt = 0,lcm = 1;
        bool flag = false;
        for (int j = 0;j < n;j++) {
            if ((mask & (1 << j)) == 0) continue;
            cnt++;
            int g = gcd(lcm,a[j + 1]);
            if (lcm / g > y / a[j + 1]) {
                flag = true;
                break;
            }
            lcm = lcm / g * a[j + 1];
        }
        if (flag) continue;
        if (cnt < m) continue;
        else if (cnt == m) ans += (__int128)y / lcm;
        else {
            if ((cnt - m) & 1) ans -= (__int128)y / lcm * C[cnt][m];
            else ans += (__int128)y / lcm * C[cnt][m];
        }
    }
    print(ans);
    return 0;
}