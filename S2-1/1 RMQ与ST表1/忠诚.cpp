#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int a[N],lg[N],st[N][30];

int main() {
	int m,n;
	cin >> m >> n;
	lg[1] = 0;
	for (int i = 2;i <= m;i++) lg[i] = lg[i / 2] + 1;
	for (int i = 1;i <= m;i++) cin >> a[i];
	for (int i = 1;i <= m;i++) st[i][0] = a[i];
	for (int j = 1;j <= lg[m];j++)
		for (int i = 1;i + (1 << j) - 1 <= m;i++)
			st[i][j] = min(st[i][j - 1],st[i + (1 << j - 1)][j - 1]);
	while (n--) {
		int l,r;
		cin >> l >> r;
		int k = lg[r - l + 1];
		cout << min(st[l][k],st[r - (1 << k) + 1][k]) << ' ';
	}
	return 0;
}