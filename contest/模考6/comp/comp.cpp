#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int p[N];
set<int> s;

void solve() {
    int n,ans = 0,pos = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> p[i];
    for (int i = 1;i <= n;i++) {
        int S;
        cin >> S;
        s.insert(S);
    }
    ans = max(ans,p[s.size() + 1]);
    for (auto t : s) {
        int pos = *s.upper_bound(t);
        if (ans > )
    }
    cout << ans << endl;
    return ;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}