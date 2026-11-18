#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 5e5 + 5,M = 1.5e6 + 5;
const double diff = 1e-3;
int v[N],a[N],ret[M]; // a[N] 计算对于每个 v 和 p 会导致总和降低多少

void s2BIG (string s,int a[])
{
    int al = s.length();
    for (int i = 1;i <= al;i++) a[i] = s[al - i] - '0';
    a[0] = al;
}

void printBIG(int a[])
{
    int al = a[0];
    for (int i = al;i >= 1;i--) cout << a[i];
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

void divBIG(int a[],int b,int c[])
{
    int cl = a[0];
    long long r = 0;
    for (int i = cl;i >= 1;i--)
    {
        r = r * 10 + a[i];
        c[i] = r / b;
        r %= b;
    }
    while (c[cl] == 0 && cl > 1) cl--;
    c[0] = cl;
}

void C(int n,int m) {
    s2BIG("1",ret);
    for (int i = n;i > m;i--) mulBIG(ret,i,ret);
    for (int i = n - m;i >= 1;i--) divBIG(ret,i,ret);
    printBIG(ret);
    cout << endl;
    return ;
}

int main() {
    // freopen("drum.in","r",stdin);
    // freopen("drum.out","w",stdout);
    int n,k,b;
    long long sum = 0;
    cin >> n >> k >> b;
    for (int i = 1;i <= n;i++)  {
        cin >> v[i];
        sum += v[i];
    }
    sum *= 100;
    for (int i = 1;i <= n;i++) {
        int p;
        cin >> p;
        a[i] = v[i] * (100 - p);
    }
    sort(a + 1,a + n + 1);
    int cnt = 0; // 连续有多少个相等
    for (int i = 1;i <= k;i++) {
        sum -= a[i];
        if (a[i] == a[i - 1]) cnt++;
        else cnt = 1;
    }
    double ans = 1.00 * sum / 100.00;
    if (!b) printf("%.5lf\n",ans);
    else {
        int cur = k,cnt2 = cnt;
        while (a[++cur] == a[cur - 1]) cnt2++;
        printf("%.5lf\n",ans);
        C(cnt2,cnt);
    }
    return 0;
}