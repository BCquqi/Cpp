#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
int dfn[N],low[N],idx = 0,ans = 0;
void init() {
	for (int i = 1;i < N;i++) G[i].clear();
	memset(dfn,0,sizeof dfn);
	memset(low,0,sizeof low);
	idx = 0,ans = 0;
}

void tarjan(int x) {
	dfn[x] = low[x] = ++idx;
	bool flag = false;
	int child = 0;
	for (auto y : G[x]) {
		if (!dfn[y]) {
			child++;
			tarjan(y);
			low[x] = min(low[x],low[y]);
			if (low[y] >= dfn[x]) flag = true;
		}
		else low[x] = min(low[x],dfn[y]);
	}
	if (x == 1 && child < 2) flag = false;
	if (flag) ans++;
}

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		init();
		while (true) {
			int x;
			cin >> x;
			if (x == 0) break;
			while (true) {
				int y;
				cin >> y;
				G[x].push_back(y);
				G[y].push_back(x);
				if (getchar() == '\n') break;
			}
		}
		tarjan(1);
		cout << ans << endl;
	}
	return 0;
}