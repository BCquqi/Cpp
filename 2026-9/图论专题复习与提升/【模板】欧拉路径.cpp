#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 2e5 + 5;
vector<int> G[N];
int out[N],in[N];
int cur[N],stk[N],top = 0,ans[N],cnt = 0;

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        out[u]++, in[v]++;
    }
    int s = 0,e = 0,cnts = 0,cnte = 0;
    for (int i = 1;i <= n;i++)
        if (out[i] - in[i] == 1) s = i, cnts++;
        else if (in[i] - out[i] == 1) e = i, cnte++;
        else if (in[i] != out[i]) {
            cout << "No" << endl;
            return 0;
        }
    if (cnts == 0 && cnte == 0) {
        for (int i = 1;i <= n;i++)
            if (out[i]) {
                s = i;
                break;
            }
        if (s == 0) s = 1;
    }
    else if (cnts != 1 || cnte != 1) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 1;i <= n;i++)
        sort(G[i].begin(), G[i].end());
    stk[++top] = s;
    while (top) {
        int u = stk[top];
        if (cur[u] < G[u].size())
            stk[++top] = G[u][cur[u]++];
        else 
            ans[++cnt] = u, top--;
    }
    if (cnt != m + 1) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = cnt;i >= 1;i--)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}