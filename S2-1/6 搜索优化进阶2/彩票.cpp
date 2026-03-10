#include<iostream>
#include<cmath>
using namespace std;

const int N = 55;
const double eps = 1e-10;
int n,m,x,y,ans = 0;
double p,s[N];

void dfs(int step,double sum,int cnt) {
	if (cnt == n) {
		if (abs(sum - p) < eps) ans++;
		return ;
	}
	if (step > m || cnt > n) return ;
	if (m - step + 1 < n - cnt) return ;
	if (sum + s[step + n - cnt - 1] - s[step - 1] < p - eps) return ;
	if (sum + s[m] - s[m - n + cnt] > p + eps) return ;
	dfs(step + 1,sum + 1.0 / step,cnt + 1);
	dfs(step + 1,sum,cnt);
}

int main() {
	cin >> n >> m >> x >> y;
	p = x * 1.0 / y;
	for (int i = 1;i <= m;i++) s[i] = s[i - 1] + 1.0 / i;
	dfs(1,0,0);
	cout << ans << endl;
	return 0;
}