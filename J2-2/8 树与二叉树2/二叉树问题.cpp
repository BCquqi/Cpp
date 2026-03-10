#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int l[N],r[N],p[N],ans1 = 0,ans2 = 0,ans3 = 0,dep[N],bre[N];

void dfs(int root,int depth) {
	ans1 = max(ans1,depth);
	dep[root] = depth;
	bre[depth]++;
	if (l[root]) dfs(l[root],depth + 1);
	if (r[root]) dfs(r[root],depth + 1);
	return ;
}

int main() {
	int n,u,v,rt;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> l[i] >> r[i];
		p[l[i]] = p[r[i]] = i;
	}
	cin >> u >> v;
	for (int i = 1;i <= n;i++) if (!p[i]) rt = i;
	dfs(rt,1);
	for (int i = 1;i <= ans1;i++) ans2 = max(ans2,bre[i]);
	while (u != v) {
		if (dep[u] > dep[v]) u = p[u];
		else v = p[v];
		ans3++;
	}
	cout << ans1 << endl << ans2 << endl << ans3 << endl;
	return 0;
}