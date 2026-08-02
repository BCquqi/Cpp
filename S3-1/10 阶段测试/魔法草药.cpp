#include<iostream>
#include<map>
#include<cmath>
using namespace std;

const int N = 25;
long long dp[(1 << 22) + 5],ans[305],x[305],y[305],flag[305][305];

int main() {
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		cin >> x[i] >> y[i];
		flag[x[i] - 1][y[i] - 1] = flag[y[i] - 1][x[i] - 1] = true;
	}
	dp[0] = 0,ans[0]++;
	for (int i = 1;i < (1 << n);i++) { // 顺序不影响，不妨设最后一个加入的是倒数第一个 1
		int x = i & -i,cur = __lg(x);
		int tmp = i ^ x,cnt = 0; // 变为 0
		for (int j = 0;j < n;j++)
			if ((tmp >> j) & 1 && flag[cur][j]) cnt++;
		dp[i] = dp[tmp] + cnt;
		ans[dp[i]]++;
	}
	for (int i = 0;i <= m;i++) cout << ans[i] << ' ';
	cout << endl;
	return 0;
}