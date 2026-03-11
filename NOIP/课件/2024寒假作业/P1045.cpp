#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

long long a[1005] = {1};

int main()
{
    int p;
    cin >> p;
    int ans = p * log10(2) + 1;
    cout << ans << endl;
    for (;p >= 1;p -= 10)
    {
        long long cnt = 0;
        for (int i = 0;i <= 500 - 1;i++)
        {
            if (p > 10) a[i] <<= 10;
            else a[i] <<= p;
            a[i] += cnt;
            cnt = a[i] / 10;
            a[i] %= 10;
        }
    }
    a[0] -= 1;
    for (int i = 500 - 1;i >= 0;i--)
    {
        putchar(a[i] + '0');
        if(i % 50 == 0) putchar('\n');
    }
    return 0;
}
