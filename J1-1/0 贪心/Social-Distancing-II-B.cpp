#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
	int x;
	bool s;
} a[1005];

bool cmp(Node cowx, Node cowy)
{
	return cowx.x < cowy.x;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i].x >> a[i].s;
	sort(a + 1,a + n + 1,cmp);
	int r = 1e9;
	for (int i = 2;i < n;i++)
	{
		if (a[i - 1].s && !a[i].s) r = min(a[i].x - a[i - 1].x,r);
		if (a[i + 1].s && !a[i].s) r = min(a[i + 1].x - a[i].x,r);
	}
	int ans = 0;
	for (int i = 1;i <= n;i++)
		if (a[i].s && (!a[i - 1].s || a[i].x - a[i - 1].x >= r)) ans++;
	cout << ans << endl;
	return 0;
}