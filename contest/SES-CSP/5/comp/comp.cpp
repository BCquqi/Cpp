#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
int p[N];
vector<int> v;

void solve() {
    v.clear();
    int n,ans = 0,pos = 0;
    cin >> n;
    for (int i = 1;i <= n + 1;i++) cin >> p[i];
    for (int i = 1;i <= n;i++) {
        int s;
        cin >> s;
        if (s) v.push_back(s);
    }
    sort(v.begin(),v.end());
    int tmp = upper_bound(v.begin(),v.end(),1) - v.begin();
    if (p[v.size() - tmp + 1] > ans) ans = p[v.size() - tmp + 1],pos = 1;
    for (auto t : v) {
        tmp = upper_bound(v.begin(),v.end(),t) - v.begin();
        if (p[v.size() - tmp + 1] > ans || (p[v.size() - tmp + 1] == ans && pos > t)) ans = p[v.size() - tmp + 1],pos = t;
    }
    cout << ans << ' ' << pos << endl;
    return ;
}

int main() {
    freopen("comp.in","r",stdin);
    freopen("comp.out","w",stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}