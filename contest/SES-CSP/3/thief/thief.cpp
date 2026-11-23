#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 1e3 + 5;
int a[N],b[N];

int main() {
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	int n,mn = 1e9;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		if (i % 2 == 1) mn = min(mn,a[i]);
	}
	if (n % 2 == 0) cout << 0 << endl;
	else cout << mn - 1 << endl;
	return 0;
}
