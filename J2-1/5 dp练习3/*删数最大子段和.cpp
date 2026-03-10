#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e6 + 5;
long long a[N],l[N],r[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) l[i] = max(l[i - 1] + a[i],a[i]);
	for (int i = n;i >= 1;i--) r[i] = max(r[i + 1] + a[i],a[i]);
	long long ans = 0;
	for (int i = 1;i <= n;i++) ans = max(ans,max(l[i - 1] + r[i + 1],max(l[i - 1],r[i + 1])));
	cout << ans << endl;
	return 0;
}