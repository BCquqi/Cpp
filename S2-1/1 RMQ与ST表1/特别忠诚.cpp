#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int a[N],lg[N],st[N][30],stid[N][30];

int main() {
	int m,n;
	cin >> m >> n;
	for (int i = 1;i <= m;i++) cin >> a[i];
	for (int i = 2;i <= m;i++) lg[i] = lg[i / 2] + 1;
	for (int i = 1;i <= m;i++) st[i][0] = a[i],stid[i][0] = i;
	for (int j = 1;j <= lg[m];j++)
		for (int i = 1;i + (1 << j) - 1 <= m;i++) {
			st[i][j] = min(st[i][j - 1],st[i + (1 << j - 1)][j - 1]);
			if (st[i][j] == st[i][j - 1]) stid[i][j] = stid[i][j - 1];
			else stid[i][j] = stid[i + (1 << j - 1)][j - 1];
		}
	while (n--) {
		int l,r;
		cin >> l >> r;
		int k = lg[r - l + 1];
		cout << ((st[l][k] <= st[r - (1 << k) + 1][k]) ? stid[l][k] : stid[r - (1 << k) + 1][k]) << endl;
	}
	return 0;
}