#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5e5 + 5;
int a[N];

int main() {
	int n,ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++)
		for (int j = i + 1;j <= n;j++)
			if (min(a[i],a[j]) == i && max(a[i],a[j]) == j) ans++;
	cout << ans << endl;
	return 0;
}
