#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1005,M = 20005;
struct Node {int a,b;} s[N];
int ans[M],tmp[M],x[M];

void s2BIG (string s,int a[]) // s to BIG
{
    int al = s.length();
    for (int i = 1;i <= al;i++) a[i] = s[al - i] - '0';
    a[0] = al;
}

void printBIG(int a[]) // printf BiG
{
    int al = a[0];
    for (int i = al;i >= 1;i--) cout << a[i];
}

bool cmpBIG(int a[],int b[]) // compare BIG(a,b)
{
    int al = a[0],bl = b[0];
    if (al != bl) return al < bl;
    for (int i = al;i >= 1;i--) if (a[i] != b[i]) return a[i] < b[i];
    return false;
}

void divBIG(int a[],int b,int c[]) // div BIG a with b to c
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

void mulBIG(int a[],int b,int c[]) // mul BIG a with b to c
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

signed main() {
    int n;
    string a0,b0;
    cin >> n >> a0 >> b0;
    for (int i = 1;i <= n;i++) cin >> s[i].a >> s[i].b;
    sort(s + 1,s + n + 1,[](Node x,Node y) {return x.a * x.b < y.a * y.b;});
    s2BIG(a0,tmp);
    s2BIG("0",ans);
    for (int i = 1;i <= n;i++) {
        divBIG(tmp,s[i].b,x);
        if (cmpBIG(ans,x)) {
            mulBIG(x,1,ans); // 赋值
        }
        mulBIG(tmp,s[i].a,tmp);
    }
    printBIG(ans);
    cout << endl;
    return 0;
}