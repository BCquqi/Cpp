#include<iostream>
#include<algorithm>
using namespace std;

int w[100005];

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> w[i];
	sort(w + 1,w + n + 1,greater<int>());
	int ans = 0;
	for (int i = 1;i <= n;i++)
		if (w[i] >= i - 1)
			ans++;
	cout << ans << endl;
	return 0;
}