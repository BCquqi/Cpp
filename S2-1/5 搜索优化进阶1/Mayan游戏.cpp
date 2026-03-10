#include<iostream>
using namespace std;

const int N = 10;
int mp[N][N],cnt = 0,n,ans[N][N],flag = false,vis[N][N];

void copy(int a[N][N],int b[N][N]) {
	for (int i = 1;i <= 7;i++)
		for (int j = 1;j <= 5;j++)
			a[i][j] = b[i][j];
}

bool check() {
	for (int j = 1;j <= 5;j++)
		if (mp[1][j]) return false;
	return true;
}

void down() {
	for (int j = 1;j <= 5;j++) {
		int b[10] = {},cnt = 0;
		for (int i = 1;i <= 7;i++)
			if (mp[i][j]) b[++cnt] = mp[i][j];
		for (int i = 1;i <= 7;i++) mp[i][j] = b[i];
 	}
}

bool remove() {
	for (int i = 1;i <= 7;i++)
		for (int j = 1;j <= 5;j++) {
			if (!mp[i][j]) continue;
			int c =  mp[i][j];
			if (mp[i - 1][j] == c && mp[i + 1][j] == c)
				vis[i - 1][j] = vis[i][j] = vis[i + 1][j] = true;
			if (mp[i][j - 1] == c && mp[i][j + 1] == c)
				vis[i][j - 1] = vis[i][j] = vis[i][j + 1] = true;
		}
	bool flag = false;
	for (int i = 1;i <= 7;i++)
		for (int j = 1;j <= 5;j++)
			if (vis[i][j]) mp[i][j] = vis[i][j] = 0,flag = true;
	return flag;
}

void move(int i,int j,int x) {
	swap(mp[i][j],mp[i][j + x]);
	down();
	while (remove()) down();
}

void dfs(int step) {
	if (flag) return ;
	if (check()) {
		flag = true;
		for (int i = 1;i <= n;i++) cout << ans[i][1] << ' ' << ans[i][2] << ' ' << ans[i][3] << endl;
		return ;
	}
	if (step > n) return ;
	int tmp[N][N] = {};
	copy(tmp,mp);
	for (int j = 1;j <= 5;j++)
		for (int i = 1;i <= 7;i++) {
			if (!mp[i][j]) break;
			if (j < 5 && mp[i][j] != mp[i][j + 1]) {
				// cout << i << ' ' << j << endl;
				ans[step][1] = j - 1,ans[step][2] = i - 1,ans[step][3] = 1;
				move(i,j,1);
				dfs(step + 1);
				copy(mp,tmp);
			}
			if (j > 1 && !mp[i][j - 1]) {
				ans[step][1] = j - 1,ans[step][2] = i - 1,ans[step][3] = -1;
				move(i,j,-1);
				dfs(step + 1);
				copy(mp,tmp);
			}
		}
}

int main() {
	cin >> n;
	for (int j = 1;j <= 5;j++) {
		int x,cnt = 0;
		while (cin >> x) {
			if (x == 0) break;
			mp[++cnt][j] = x;
		}
	}
	dfs(1);
	if (!flag) cout << -1 << endl;
	return 0;
}