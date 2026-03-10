#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	while (m--) {
		int l,r,maxn = 0,scmaxn = 0;
		cin >> l >> r;
		for (int i = l;i <= r;i++) maxn = max(maxn,a[i]);
		for (int i = l;i <= r;i++)
			if (a[i] != maxn) scmaxn = max(scmaxn,a[i]);
		cout << maxn << ' ' << scmaxn << '\n';
	}
	return 0;
}