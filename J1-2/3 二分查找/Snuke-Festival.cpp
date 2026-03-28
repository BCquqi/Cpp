#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
long long a[N],b[N],c[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) cin >> b[i];
	for (int i = 1;i <= n;i++) cin >> c[i];
	sort(a + 1,a + n + 1);
	sort(b + 1,b + n + 1);
	sort(c + 1,c + n + 1);
	long long ans = 0;
	for (int i = 1;i <= n;i++)
	{
		long long pos1 = upper_bound(c + 1,c + n + 1,b[i]) - c;
		long long pos2 = lower_bound(a + 1,a + n + 1,b[i]) - a;
		ans += (n - pos1 + 1) * (pos2 - 1);
	}
	cout << ans << endl;
}
