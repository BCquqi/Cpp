#include<iostream>
#include<vector>
using namespace std;

const int N = 1e4 + 5;
int dfn[N],low[N],st[N],id[N],d[N],idx = 0,top = 0,cnt_ecc = 0;
bool bridge[N];

struct Edge {
    int u,i;
};

vector<Edge> G[N];

void tarjan(int x,int pre) {
	dfn[x] = low[x] = ++idx;
    st[++top] = x;
    for (auto [y,i] : G[x]) {
        if (i == pre) continue;
        if (!dfn[y]) {
            tarjan(y,i);
            low[x] = min(low[x],low[y]);
            if (low[y] > dfn[x]) bridge[i] = true;
        }
        else low[x] = min(low[x],dfn[y]);
    }
    if (low[x] == dfn[x]) {
        int y;
        cnt_ecc++;
        do {
            y = st[top--];
            id[y] = cnt_ecc;
        } while (x != y);
    }
}

int main() {
	int f,r,ans = 0;
	cin >> f >> r;
	for (int i = 1;i <= r;i++) {
		int u,v;
		cin >> u >> v;
		G[u].push_back({v,i});
		G[v].push_back({u,i});
	}
    tarjan(1,0);
    for (int i = 1;i <= f;i++)
        for (auto [j,t] : G[i]) {
            int x = id[i],y = id[j];
            if (x != y) d[x]++;
        }
    for (int i = 1;i <= cnt_ecc;i++)
        if (d[i] == 1) ans++;
    cout << (ans + 1) / 2 << endl;
	return 0;
}