#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e5 + 5;
int h[N];

int main(){
	int n,a,b,k;
	cin >> n >> a >> b >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> h[i];
		h[i] = h[i] % (a + b) != 0 ? h[i] % (a + b) : a + b;
	}
	sort(h + 1,h + n + 1);
	int sum = 0,ans = 0;
	for (int i = 1;i <= n;i++)
		if (sum + (h[i] + a - 1) / a - 1 <= k) sum += (h[i] + a - 1) / a - 1,ans++;
	cout << ans << endl;
	return 0;
}