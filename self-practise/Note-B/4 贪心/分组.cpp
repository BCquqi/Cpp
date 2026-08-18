#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;

const int N = 100005;
int a[N];
map<int, priority_queue<int, vector<int>, greater<int>>> mp;
// 队尾实力值对应所有组的人数

int main() {
    int n,ans = 1e9;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for (int i = 1;i <= n;i++) {
        int x = a[i];
        if (!mp[x - 1].empty()) {
            int cnt = mp[x - 1].top();
            mp[x - 1].pop();
            mp[x].push(cnt + 1);
        }
        else mp[x].push(1);
    }
    for (auto p : mp)
        if (!p.second.empty()) ans = min(ans,p.second.top());
    cout << ans << endl;
    return 0;
}