#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

long long a[100005],sum[100005];
long long ans = 0;

int main(){
	long long n,k;
	cin >> n >> k;
	sum[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	int pos = 1;
	for (int l = 1;l <= n;l++)
	{
		if (sum[n] - sum[l - 1] < k) break;
		for (int r = pos;r <= n;r++)
		{
			if (sum[r] - sum[l - 1] >= k) 
			{
				ans += n - r + 1;
				pos = r;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
