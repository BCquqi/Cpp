#include<iostream>
using namespace std;

const int N = 2e5 + 5;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,q;
	long long sum = 0;
	cin >> n >> q;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		sum += a[i];
	}
	cout << sum << '\n';
	while (q--) {
		int l,r,x;
		sum = 0;
		cin >> l >> r >> x;
		for (int i = 1;i <= n;i++)
			if (a[i] >= l && a[i] <= r) a[i] = x;
		for (int i = 1;i <= n;i++) sum += a[i];
		cout << sum << '\n';
	}
	return 0;
}