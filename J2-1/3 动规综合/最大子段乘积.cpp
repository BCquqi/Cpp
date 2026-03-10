#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int a[N],dpmax1[N],dpmin1[N],dpmax2[N],dpmin2[N],rmax[N],lmax[N],rmin[N],lmin[N];

int main()
{
	int n;
	cin >> n;
	lmax[0] = -1e9,lmin[0] = 1e9;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		dpmax1[i] = max(a[i],dpmax1[i - 1] + a[i]);
		dpmin1[i] = min(a[i],dpmin1[i - 1] + a[i]);
		lmax[i] = max(lmax[i - 1],dpmax1[i]);
		lmin[i] = min(lmin[i - 1],dpmin1[i]);
	}
	rmax[n + 1] = -1e9,rmin[n + 1] = 1e9;
	for (int i = n;i >= 1;i--)
	{
		dpmax2[i] = max(a[i],dpmax2[i + 1] + a[i]);
		dpmin2[i] = min(a[i],dpmin2[i + 1] + a[i]);
		rmax[i] = max(rmax[i + 1],dpmax2[i]);
		rmin[i] = min(rmin[i + 1],dpmin2[i]);
	}
	long long ans = -2e18;
	for (int i = 2;i <= n - 1;i++)
		ans = max(ans,1ll * lmax[i - 1] * rmax[i + 1]),
		ans = max(ans,1ll * lmin[i - 1] * rmin[i + 1]);
	cout << ans << endl;
	return 0;
}
