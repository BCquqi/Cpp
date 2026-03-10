#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

int w[N],c[N];

int main()
{
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> w[i];
	for (int i = 1;i <= m;i++) cin >> c[i];
	sort(w + 1,w + n + 1);
	sort(c + 1,c + m + 1);
	int ans = n,cur = 1;
	for (int i = 1;i <= n;i++)
	{
		if (w[i] < c[cur]) ans--;
		else cur++;
	}
	cout << ans << endl;
	return 0;
}