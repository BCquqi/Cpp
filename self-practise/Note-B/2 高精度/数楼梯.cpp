#include<iostream>
using namespace std;

const int N = 5005;
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
    int n;
    cin >> n;
    s2BIG("1",a); s2BIG("2",b);
    if (n <= 2) {
        cout << n << endl;
        return 0;
    }
    for (int i = 3;i <= n;i++) {
        addBIG(a,b,c);
        for(int j = 0;j <= c[0];j++) a[j] = b[j];
        for(int j = 0;j <= c[0];j++) b[j] = c[j];
    }
    printBIG(b);
    return 0;
}