#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
int a[N],b[N],copya[N],copyb[N];

int main()
{
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		copya[i] = a[i];
	}
	for (int i = 1;i <= m;i++)
	{
		cin >> b[i];
		copyb[i] = b[i];
	}
	sort(a + 1,a + n + 1);
	sort(b + 1,b + m + 1);
	for (int i = 1;i <= n;i++)
	{
		int pos = upper_bound(b + 1,b + m + 1,copya[i]) - b;
		cout << pos - 1 << ' ';
	}
	cout << endl;
	for (int i = 1;i <= m;i++)
	{
		int pos = upper_bound(a + 1,a + n + 1,copyb[i]) - a;
		cout << pos - 1 << ' ';
	}
	return 0;
}
