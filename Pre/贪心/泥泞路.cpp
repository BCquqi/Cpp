#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Node {
	int b,e;
} a[10005];

bool cmp(Node x,Node y)
{
	return x.b < y.b;
}

int main() {
	int n,l;
	cin >> n >> l;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].b >> a[i].e;
	}
	sort(a + 1,a + n + 1,cmp);
	int ans = 0,p = 0;
	for (int i = 1;i <= n;i++)
	{
		int st = max(a[i].b,p);
		int len = a[i].e - st;
		int cnt = max(0,(len + l - 1) / l);
		ans += cnt;
		p = st + cnt * l;
	}
	cout << ans << endl;
    return 0;
}
