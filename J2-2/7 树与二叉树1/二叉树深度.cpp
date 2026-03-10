#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 5;
int l[N],r[N],p[N],ans = 0;

void dfs(int u,int dep) {
	ans = max(ans,dep);
	if (l[u]) dfs(l[u],dep + 1);
	if (r[u]) dfs(r[u],dep + 1);
	return ;
}

int main() {
	int n,rt;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> l[i] >> r[i];
		p[l[i]] = p[r[i]] = i;
	}
	for (int i = 1;i <= n;i++) if (!p[i]) rt = i;
	dfs(rt,1);
	cout << ans << endl;
	return 0;
}