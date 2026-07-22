#include<iostream>
#include<set>
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	while (m--) {
		int x,y;
		cin >> x >> y;
		for (int i = 1;i <= n;i++)
			if (a[i] == x) a[i] = y;
		int ans = 2147483647;
		for (int i = 1;i <= n;i++)
			for (int j = i + 1;j <= n;j++)
				if (a[i] == a[j]) ans = min(ans,j - i);
		cout << ans << '\n';
	}
	return 0;
}