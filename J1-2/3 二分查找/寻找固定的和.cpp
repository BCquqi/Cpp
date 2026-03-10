#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int x[200005],y[200005];

int main(){
	int n,k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> x[i];
	for (int i = 1;i <= n;i++) cin >> y[i];
	sort(x + 1,x + n + 1);
	sort(y + 1,y + n + 1);
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		if (x[i] == x[i - 1]) continue;
		int xlowpos = lower_bound(x + 1,x + n + 1,x[i]) - x;
		int xupppos = upper_bound(x + 1,x + n + 1,x[i]) - x;
		int yupppos = upper_bound(y + 1,y + n + 1,k - x[i]) - y;
		int ylowpos = lower_bound(y + 1,y + n + 1,k - x[i]) - y;
		ans += min(xupppos - xlowpos,yupppos - ylowpos);
	}
	cout << ans << endl;
	return 0;
}
