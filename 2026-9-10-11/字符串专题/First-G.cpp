#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 3e5 + 5,M = 26;
int ch[N][M],cnt[N],sum[N],id = 1,in[M];
string s[N],ans[N];

vector<int> G[M];

void insert(string s) {
    int x = 1;
    for (auto c : s) {
        int i = c - 'a';
        if (!ch[x][i]) ch[x][i] = ++id;
        x = ch[x][i];
        sum[x]++;
    }
    cnt[x]++;
}

bool topo_sort() {
    queue<int> q;
    for (int i = 0;i < 26;i++)
        if (in[i] == 0) q.push(i);
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cnt++;
        for (auto v : G[u])
            if (--in[v] == 0) q.push(v);
    }
    if (cnt < 26) return true;
    else return false;
}

bool check(string s) {
    int x = 1;
    for (int i = 0;i < 26;i++) G[i].clear();
    memset(in,0,sizeof in);
    for (auto c : s) {
        int i = c - 'a';
        if (cnt[x] == 1) return false;
        for (int j = 0;j < 26;j++)
            if (ch[x][j] && j != i) {
                G[i].push_back(j);
                in[j]++;
            }
        x = ch[x][i];
    }
    if (topo_sort()) return false;
    else return true;
}

int main() {
    int n,cur = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> s[i];
        insert(s[i]);
    }
    for (int i = 1;i <= n;i++)
        if (check(s[i])) ans[++cur] = s[i];
    cout << cur << endl;
    for (int i = 1;i <= cur;i++) cout << ans[i] << endl;
    return 0;
}