#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 200005;
int a[N],b[N];
long long minn = 1e9,seco = 1e9;

void fun(int x)
{
	if (x <= minn) seco = minn,minn = x;
	else if (x < seco) seco = x;
}

int main()
{
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= m;i++) cin >> b[i];
	sort(b + 1,b + m + 1);
	for (int i = 1;i <= n;i++)
	{
		int pos = lower_bound(b + 1,b + m + 1,a[i]) - b;
		if (pos <= m) fun(b[pos] - a[i]);
		if (pos + 1 <= m) fun(b[pos + 1] - a[i]);
		if (pos - 1 >= 1) fun(a[i] - b[pos - 1]);
		if (pos - 2 >= 1) fun(a[i] - b[pos - 2]);
	}
	cout << minn << ' ' << seco << endl;
	return 0;
}
