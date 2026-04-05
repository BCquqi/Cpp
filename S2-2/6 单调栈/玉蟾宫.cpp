#include<iostream>
#include<stack>
using namespace std;

const int N = 1005;
int s[N][N],dp[N][N],l[N],r[N];
char a[N][N];
stack<int> st[N],st1[N];

int main() {
	int n,m,ans = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> a[i][j];
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++) {
			if (a[i][j] == 'R') s[i][j] = 0;
			else s[i][j] = s[i - 1][j] + 1;
		}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			while (!st[i].empty() && s[i][st[i].top()] >= s[i][j]) st[i].pop();
			l[j] = st[i].empty() ? 0 : st[i].top();
			st[i].push(j);
		}
		for (int j = m;j >= 1;j--) {
			while (!st1[i].empty() && s[i][st1[i].top()] >= s[i][j]) st1[i].pop();
			r[j] = st1[i].empty() ? m + 1 : st1[i].top();
			st1[i].push(j);
		}
		for (int j = 1;j <= m;j++)
			ans = max(ans,(r[j] - l[j] - 1) * s[i][j]);
	}
	cout << 3 * ans << endl;
	return 0;
}