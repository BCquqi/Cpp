#include<iostream>
#include<cmath>
using namespace std;

int n,m,ans = 1e9;

void dfs(int step,int r,int h,int v,int s) {
	if (s >= ans) return ;
	if (step > m) {
		if (v == n)
			ans = min(ans,s);
		return ;
	}
	int vmax = v,vmin = v,k = 0;
	for (int i = step;i <= m;i++) {
		k++;
		vmax += (r - k) * (r - k) * (h - k);
		vmin += k * k * k;
	}
	if (vmax < n || vmin > n) return ;
	for (int i = r - 1;i >= m - step + 1;i--)
		for (int j = h - 1;j >= m - step + 1;j--)
			dfs(step + 1,i,j,v + i * i * j,s + 2 * i * j);
}

int main() {
	cin >> n >> m;
	for (int i = sqrt(n);i >= m;i--)
		for (int j = n / (i * i);j >= m;j--)
			dfs(2,i,j,i * i * j,i * i + 2 * i * j);
	if (ans == 1e9) ans = 0;
	cout << ans << endl;
	return 0;
}