#include<iostream>
using namespace std;

const int  N = 4e5 + 5;
int a[N];

int main() {
	int n;
	long long ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++)
		for (int j = i + 1;j <= n;j++)
			ans += max(a[j] - a[i],0);
	cout << ans << endl;
	return 0;
}