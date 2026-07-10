#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int c[100005];

int main()
{
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> c[i];
    int m,p1,s1,s2;
    cin >> m >> p1 >> s1 >> s2;
    c[p1] += s1;
    int minn = 1e9,ans = 0;
    long long diff = 0;
    for (int i = 1;i <= n;i++)
        diff += 1ll * c[i] * (i - m);
    for (int i = 1;i <= n;i++)
    {
        long long newd = abs(diff + 1ll * s2 * (i - m));
        if (newd < minn) minn = newd,ans = i;
    }
    cout << ans << endl;
    return 0;
}