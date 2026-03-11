#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct Missle {
	int x,y;
	int d1,d2;
} a[100005];

bool cmp(Missle x,Missle y)
{
	return x.d1 < y.d1;
}

int b[100005];

int main(){
	int x1,x2,y1,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].x >> a[i].y;
		a[i].d1 = (x1 - a[i].x) * (x1 - a[i].x) + (y1 - a[i].y) * (y1 - a[i].y);
		a[i].d2 = (x2 - a[i].x) * (x2 - a[i].x) + (y2 - a[i].y) * (y2 - a[i].y);
	}
	sort(a + 1,a + n + 1,cmp);
	int r1 = 0,r2 = 0,ans = 1e9;
	b[n] = a[n].d2;
	for (int i = n - 1;i >= 1;i--)
	{
		b[i] = max(b[i + 1],a[i].d2);
	}
	for (int i = 0;i <= n;i++)
	{
		r1 = a[i].d1;
		r2 = b[i + 1];
		ans = min(ans,r1 + r2);
	}
	cout << ans << endl;
	return 0;
}
