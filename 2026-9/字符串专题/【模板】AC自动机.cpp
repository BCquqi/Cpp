#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;

const int N = 2e6 + 6,NN = 2e5 + 6,M = 26;
int n,idx[N];
int ch[NN][M],fail[NN],sum[NN],cnt[NN],id = 1;
vector<int> G[NN];

void insert(string s,int &idx) {
    int x = 1;
    for (auto c : s) {
        int i = c - 'a';
        if (!ch[x][i]) ch[x][i] = ++id;
        x = ch[x][i];
    }
    cnt[x]++, idx = x;
}

void query(string s) {
    int x = 1;
    for (auto c : s) x = ch[x][c - 'a'], sum[x]++;
}

void build() {
    queue<int> q;
    for (int i = 0;i < M;i++) {
        if (ch[1][i]) {
            fail[ch[1][i]] = 1;
            q.push(ch[1][i]);
            G[1].push_back(ch[1][i]);
        }
        else ch[1][i] = 1;
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 0;i < M;i++) {
            if (ch[x][i]) {
                int y = ch[x][i];
                fail[y] = ch[fail[x]][i];
                G[fail[y]].push_back(y);
                q.push(y);
            }
            else ch[x][i] = ch[fail[x]][i];
        }
    }
}

void dfs(int u) {
    for (auto v : G[u]) {
        dfs(v);
        sum[u] += sum[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        string s;
        cin >> s;
        insert(s,idx[i]);
    }
    build();
    string s;
    cin >> s;
    query(s);
    dfs(1);
    for (int i = 1;i <= n;i++)
        cout << sum[idx[i]] << endl;
    return 0;
}