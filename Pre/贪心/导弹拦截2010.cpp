#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
	int d1,d2;
} a[100005];

bool cmp(Node x,Node y)
{
	return x.d1 < y.d1;
}

int main(){ 
	int x1,y1,x2,y2,n;
	cin >> x1 >> y1 >> x2 >> y2 >> n;
	for (int i = 1;i <= n;i++)
	{
		int x,y;
		cin >> x >> y;
		a[i].d1 = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
		a[i].d2 = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);
	}
	sort(a + 1,a + n + 1,cmp);
	int r1 = a[n].d1,r2 = 0,ans = r1;
	for (int i = n - 1;i >= 1;i--)
	{
		r1 = a[i].d1;
		r2 = max(r2,a[i + 1].d2);
		ans = min(ans,r1 + r2);
	}
	cout << ans << endl;
	return 0;
}
