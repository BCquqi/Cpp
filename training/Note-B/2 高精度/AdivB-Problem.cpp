#include<iostream>
using namespace std;

const int N = 5005;
int a[N],c[N];

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

int main() {
    string s1;
    int b;
    cin >> s1 >> b;
    s2BIG(s1,a);
    divBIG(a,b,c);
    printBIG(c);
    return 0;
}