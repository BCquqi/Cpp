#include<iostream>
using namespace std;

const int N = 2005;
int B,a[N],b[N],c[N];

void s2BIG (string s,int a[])
{
    int al = s.length();
    for (int i = 1;i <= al;i++) {
        if ('0' <= s[al - i] && s[al - i] <= '9')
            a[i] = s[al - i] - '0';
        else a[i] = s[al - i] - 'A' + 10;
    }
    a[0] = al;
}

void printBIG(int a[])
{
    int al = a[0];
    for (int i = al;i >= 1;i--) {
        if (0 <= a[i] && a[i] <= 9) cout << a[i];
        else cout << char(a[i] - 10 + 'A');
    }
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
        c[i] = t % B;
        u = t / B;
    }
    if (u > 0)
    {
        cl++;
        c[cl] = u;
    }
    c[0] = cl;
}

int main() {
    cin >> B;
    string s1,s2;
    cin >> s1 >> s2;
    s2BIG(s1,a); s2BIG(s2,b);
    addBIG(a,b,c);
    printBIG(c);
    return 0;
}