#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 2e5 + 5;
int l[N],r[N],deg[N],ans[N];
bool flag[N];
vector<int> b[N],cov[N],ed[N];
queue<int> q;

int main() {
    int n,m;
    cin >> n >> m;
    l[0] = 1, r[0] = n;
    b[0].resize(n + 1);
    for (int i = 1;i <= n;i++)
        cin >> b[0][i], cov[i].push_back(0);
    for (int i = 1;i <= m;i++) {
        cin >> l[i] >> r[i];
        int len = r[i] - l[i] + 1;
        b[i].resize(len + 1);
        for (int j = 1;j <= len;j++) {
            cin >> b[i][j];
            cov[l[i] + j - 1].push_back(i);
        }
        ed[r[i]].push_back(i);
    }
    for (int i = 1;i <= n;i++) {
        for (int id : cov[i])
            if (deg[id] == 0) ans[i] = max(ans[i],b[id][i - l[id] + 1]);
        for (int id : cov[i])
            if (b[id][i - l[id] + 1] < ans[i]) deg[id]++;
        for (int id : ed[i])
            if (deg[id] == 0) q.push(id);
        while (!q.empty()) {
            int id = q.front(); q.pop();
            for (int p = l[id];p <= r[id];p++) {
                if (flag[p]) continue;
                flag[p] = true;
                for (int to : cov[p])
                    if (b[to][p - l[to] + 1] < ans[p]) {
                        deg[to]--;
                        if (deg[to] == 0 && r[to] <= i) q.push(to);
                    }
            }
        }
    }
    for (int i = 1;i <= n;i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}