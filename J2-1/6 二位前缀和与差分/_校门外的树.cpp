#include<iostream>
using namespace std;

const int N = 1e6 + 5;
int d[N];

int main()
{
	int l,m,tmp = 0,ans = 0;
	cin >> l >> m;
	while (m--)
	{
		int s,e;
		cin >> s >> e;
		d[s]++,d[e + 1]--;
	}
	for (int i = 0;i <= l;i++)
	{
		tmp += d[i];
		if (tmp == 0) ans++;
	}
	cout << ans << endl;
	return 0;
}