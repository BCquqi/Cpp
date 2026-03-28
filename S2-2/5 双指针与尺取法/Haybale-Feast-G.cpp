#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int f[N],s[N],lg[N],st[N][30];
long long sf[N];

int query(int l,int r) {
	int k = lg[r - l + 1];
	return max(st[l][k],st[r - (1 << k) + 1][k]);
}

int main() {
	int n,ans = 1e9;
	long long m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> f[i] >> s[i];
		sf[i] = sf[i - 1] + f[i];
	}
	lg[1] = 0;
	for (int i = 2;i <= n;i++) lg[i] = lg[i / 2] + 1;
	for (int i = 1;i <= n;i++) st[i][0] = s[i];
	for (int j = 1;j <= lg[n];j++)
		for (int i = 1;i + (1 << j) - 1 <= n;i++)
			st[i][j] = max(st[i][j - 1],st[i + (1 << j - 1)][j - 1]);
	for (int l = 1,r = 1;r <= n;r++)
		while (sf[r] - sf[l - 1] >= m) ans = min(ans,query(l,r)),l++;
	cout << ans << endl;
	return 0;
}