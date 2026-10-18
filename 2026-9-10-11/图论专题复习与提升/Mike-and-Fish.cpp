#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 2e5 + 5;
vector<int> G[N];
int lstu[N],lstv[N],color[N];

void dfs(int u,bool c) {
    color[u] = c;
    for (auto v : G[u])
        if (color[v] == -1) dfs(v,!c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    memset(color,-1,sizeof color);
    for (int i = 1;i <= n;i++) {
        int x,y;
        cin >> x >> y;
        if (lstu[x])
            G[lstu[x]].push_back(i), G[i].push_back(lstu[x]), lstu[x] = 0;
        else lstu[x] = i;
        if (lstv[y])
            G[lstv[y]].push_back(i), G[i].push_back(lstv[y]), lstv[y] = 0;
        else lstv[y] = i;
    }
    for (int i = 1;i <= n;i++)
        if (color[i] == -1) dfs(i,0);
    for (int i = 1;i <= n;i++)
        cout << (color[i] ? 'r' : 'b');
    cout << endl;
    return 0;
}