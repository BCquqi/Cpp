#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[100005],sum[100005];

int main(){
	int n;
	cin >> n;
	sum[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	int q;
	cin >> q;
	for (int i = 1;i <= q;i++)
	{
		int l,r;
		cin >> l >> r;
		cout << sum[r] - sum[l - 1] << endl;
	}
	return 0;
}
