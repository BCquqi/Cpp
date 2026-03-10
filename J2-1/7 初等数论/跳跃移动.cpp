#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int x[N];

int main()
{
	int n,X,ans = 0;
	cin >> n >> X;
	for (int i = 1;i <= n;i++) cin >> x[i];
	for (int i = 1;i <= n;i++)
		ans = __gcd(ans,abs(X - x[i]));
	cout << ans << endl;
	return 0;
}