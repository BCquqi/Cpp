#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
	int b,e;
} a[200005];

bool cmp(Node x,Node y)
{
	return x.b < y.b;
}

int main()
{
	int n,t;
	cin >> n >> t;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].b >> a[i].e;
	}
	sort(a + 1,a + n + 1,cmp);
	int ans = 0,pik = 1;
	int maxe = -1e9; 
	int s = 1;
	for (int i = 1;i <= n;i++)
	{
		if (a[i].b <= s && s <= a[i].e)
		{
			maxe = max(maxe,a[i].e);
		}
		if (i == n || a[i + 1].b > s)
		{
			ans++;
			s = maxe;
			if (s >= t) break;
			maxe = -1e9;
		}
	}
	cout << ans << endl;
	return 0; 
}
