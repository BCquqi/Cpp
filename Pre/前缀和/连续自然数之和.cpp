#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[100005],sum[100005],ans = 0;

int main(){
	int n;
	cin >> n;
	sum[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	int minn = 1e9;
	for (int j = 1;j <= n;j++)
	{
		ans = max(ans,sum[j] - minn);
		minn = min(minn,sum[j]);
	}
	cout << ans << endl;
	return 0;
}
