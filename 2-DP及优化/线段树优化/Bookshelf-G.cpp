#include<iostream>
#include<set>
#include<deque>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int n,l,h[N],w[N],s[N],dp[N];
struct Node {int a,h;};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> l;
    for (int i = 1;i <= n;i++)
        cin >> h[i] >> w[i], s[i] = s[i - 1] + w[i];
    deque<Node> q;
    multiset<int> st;
    int cur = 0;
    for (int i = 1;i <= n;i++) {
        while (s[i] - s[cur] > l) cur++;
        while (!q.empty()) {
            if (q.front().a >= cur) break;
            if (q.size() >= 2 && q[1].a <= cur) {
                st.erase(st.find(dp[q.front().a] + q.front().h));
                q.pop_front();
            } else {
                st.erase(st.find(dp[q.front().a] + q.front().h));
                q.front().a = cur;
                st.insert(dp[cur] + q.front().h);
                break;
            }
        }
        int tmp = i - 1;
        while (!q.empty() && q.back().h <= h[i]) {
            st.erase(st.find(dp[q.back().a] + q.back().h));
            tmp = q.back().a;
            q.pop_back();
        }
        q.push_back({tmp,h[i]});
        st.insert(dp[tmp] + h[i]);
        dp[i] = *st.begin();
    }
    cout << dp[n] << endl;
    return 0;
}