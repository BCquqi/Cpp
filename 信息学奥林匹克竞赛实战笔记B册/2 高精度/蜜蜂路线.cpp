// Fibonacci n - m + 1
#include<iostream>
using namespace std;

const int N = 1005;
int a[N],b[N],c[N];

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

void addBIG(int a[],int b[],int c[])
{
    int al = a[0],bl = b[0];
    int cl = max(al,bl);
    int u = 0;
    for (int i = 1;i <= cl;i++)
    {
        int t = u;
        if (i <= al) t += a[i];
        if (i <= bl) t += b[i];
        c[i] = t % 10;
        u = t / 10;
    }
    if (u > 0)
    {
        cl++;
        c[cl] = u;
    }
    c[0] = cl;
}

int main() {
    int m,n;
    cin >> m >> n;
    int len = n - m + 1;
    s2BIG("1",a); s2BIG("1",b);
    if (len == 1 || len == 2) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 3;i <= len;i++) {
        addBIG(a,b,c);
        for(int j = 0;j <= c[0];j++) a[j] = b[j];
        for(int j = 0;j <= c[0];j++) b[j] = c[j];
    }
    printBIG(b);
    return 0;
}