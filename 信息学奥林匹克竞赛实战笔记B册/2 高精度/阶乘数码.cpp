#include<iostream>
using namespace std;

const int N = 1e7 + 5;
int a[N];

void s2BIG (string s,int a[])
{
    int al = s.length();
    for (int i = 1;i <= al;i++) a[i] = s[al - i] - '0';
    a[0] = al;
}

void mulBIG(int a[],int b,int c[])
{
    int cl = a[0];
    long long u = 0;
    for (int i = 1;i <= cl;i++)
    {
        int t = 1ll * a[i] * b + u;
        c[i] = t % 10;
        u = t / 10;
    }
    while (u > 0)
    {
        cl++;
        c[cl] = u % 10;
        u /= 10;
    }
    c[0] = cl;
}

void solve() {
    int n,A,ans = 0;
    cin >> n >> A;
    s2BIG("1",a);
    for (int i = 1;i <= n;i++) mulBIG(a,i,a);
    for (int i = 1;i <= a[0];i++) ans += (a[i] == A);
    cout << ans << endl;
    return ;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}