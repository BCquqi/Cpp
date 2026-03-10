#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

long long a[100005];

int main(){
	int n,Q;
	cin >> n >> Q;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		a[i] -= i;
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= Q;i++)
	{
		long long d;
		cin >> d;
		int pos = lower_bound(a + 1,a + n + 1,d) - a;
		if (a[pos] == d) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
