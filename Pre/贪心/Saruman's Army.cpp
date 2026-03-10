#include<iostream>
#include<algorithm>
using namespace std;

int x[1005];

struct Node {
	int b,e;
} a[1005];

bool cmp(int x,int y)
{
	return x < y;
}

int main()
{
	int r,n;
	cin >> r >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> x[i];
	}
	sort(x + 1,x + n + 1,cmp);
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		int pos = i;
		while (pos + 1 <= n && x[pos + 1] - x[i] <= r) pos++;
		ans++;
		i = pos;
		while (pos + 1 <= n && x[pos + 1] - x[i] <= r) pos++;
		i = pos;
	}
	cout << ans << endl;
	return 0; 
}
