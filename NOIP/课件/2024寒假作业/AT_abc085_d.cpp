#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int a[100005],b[100005];

bool cmp(int a,int b)
{
	return a > b;
}

int main() {
    int n,h;
    cin >> n >> h;
    for (int i = 1;i <= n;i++)
    {
    	cin >> a[i] >> b[i];
    }
    int maxa = -1e9;
    for (int i = 1;i <= n;i++)
    {
    	maxa = max(maxa,a[i]);
    }
    sort(b + 1,b + n + 1,cmp);
    int ans = 0;
    for (int i = 1;i <= n && h > 0;i++)
    {
    	if (b[i] <= maxa) break;
    	h -= b[i];
    	ans++;
    }
    if (h > 0) ans += ceil(h * 1.0 / maxa);
    cout << ans << endl;
    return 0;
}
