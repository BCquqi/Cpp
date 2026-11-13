#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1e6 + 5;
int n;
bool ans = false;
int label[N],cnt[N],plan[N] = {1,0,1,2,0,2},side[N];

inline bool check(int plan[]) {
    memset(side,-1,sizeof side);
    deque<int> q;
    for (int i = 1;i <= n;i++) {
        if (q.empty()) side[plan[i]] = 0, q.push_front(plan[i]);
        else if (side[plan[i]] == -1)
    }
    return q.empty();
}

void dfs(int step) {
    if (ans) return ;
    if (step > n) {
        if (check(plan)) ans = true;
        return ;
    }
    if (plan[step] != -1) dfs(step + 1);
    for (int i = 0;i < n / 2;i++) {
        if (cnt[i] == 2) continue;
        cnt[i]++, plan[step] = i;
        dfs(step + 1);
        cnt[i]--, plan[step] = -1;
    }
    return ;
}

void solve() {
    memset(cnt,0,sizeof cnt); ans = false;
    cin >> n;
    cerr << check(plan) << endl;
    int u = 0;
    for (int i = 1;i <= n;i++) {
        cin >> label[i];
        if (label[i] == -1) u++;
        else cnt[label[i]]++;
        plan[i] = label[i];
    }
    if (u <= 12) {
        // dfs(1);
        // if (ans) cout << "POSSIBLE" << endl;
        // else cout << "IMPOSSIBLE" << endl;
    }
    return ;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}