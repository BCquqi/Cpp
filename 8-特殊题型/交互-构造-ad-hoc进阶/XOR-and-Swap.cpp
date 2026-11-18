#include<iostream>
#include<vector>
using namespace std;

const int N = (1 << 20) + 5;
int p[N],q[N],pos[N];
vector<pair<int,int>> ans;

int main() {
    int n;
    cin >> n;
    for (int i = 0;i < 1 << n;i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for (int i = 0;i < 1 << n;i++) cin >> q[i];
    for (int i = 0;i < 1 << n;i++) {
        if (p[i] == q[i]) continue;
        int tmp = pos[q[i]];
        swap(p[i],p[tmp]);
        pos[p[i]] = i, pos[p[tmp]] = tmp;
        ans.push_back({i,tmp});
    }
    cout << ans.size() << endl;
    for (auto it : ans) cout << it.first << ' ' << it.second << endl;
    return 0;
}