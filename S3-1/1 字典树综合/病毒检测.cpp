#include<iostream>
#include<bitset>
using namespace std;

const int N = 2.5e5 + 5,M = 26;
int ch[N][M],sum[N],cnt[N],id = 1,ans = 0;
bitset<1005> vis[N];
string s;

void dfs(int x,int i) {
    if (vis[x][i]) return ;
    vis[x][i] = true;
    if (i == s.size()) {
        ans += cnt[x];
        return ;
    }
    if (s[i] == 'A' || s[i] == 'C' || s[i] == 'T' || s[i] == 'G') {
        if (ch[x][s[i] - 'A']) dfs(ch[x][s[i] - 'A'],i + 1);
    } else if (s[i] == '?') {
        if (ch[x]['A' - 'A']) dfs(ch[x]['A' - 'A'],i + 1);
        if (ch[x]['C' - 'A']) dfs(ch[x]['C' - 'A'],i + 1);
        if (ch[x]['T' - 'A']) dfs(ch[x]['T' - 'A'],i + 1);
        if (ch[x]['G' - 'A']) dfs(ch[x]['G' - 'A'],i + 1);
    } else {
        dfs(x,i + 1);
        if (ch[x]['A' - 'A']) dfs(ch[x]['A' - 'A'],i);
        if (ch[x]['C' - 'A']) dfs(ch[x]['C' - 'A'],i);
        if (ch[x]['T' - 'A']) dfs(ch[x]['T' - 'A'],i);
        if (ch[x]['G' - 'A']) dfs(ch[x]['G' - 'A'],i);
    }
}

void insert(string s) {
    int x = 1;
    for (auto c : s) {
        int i = c - 'A';
        if (!ch[x][i]) ch[x][i] = ++id;
        x = ch[x][i];
        sum[x]++;
    }
    cnt[x]++;
}

int main() {
    int n;
    cin >> s >> n;
    for (int i = 1;i <= n;i++) {
        string t;
        cin >> t;
        insert(t);
    }
    dfs(1,0);
    cout << n - ans << endl;
    return 0;
}