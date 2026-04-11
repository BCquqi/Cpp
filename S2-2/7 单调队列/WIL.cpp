#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

const int N = 2e6 + 5;
int w[N];
long long s[N],sd[N];
deque<int> q;

int main() {
    int n,d;
    long long p;
    cin >> n >> p >> d;
    int ans = d;
    for (int i = 1;i <= n;i++) {cin >> w[i]; s[i] = w[i] + s[i - 1];}
    for (int i = d;i <= n;i++) sd[i] = s[i] - s[i - d];
    for (int L = 1,R = d + 1;R <= n;R++) {
        while (!q.empty() && q.back() - L + 1 < d) q.pop_back();
        while (!q.empty() && sd[q.front()] <= sd[R]) q.pop_front();
        q.push_front(R);
        while (!q.empty() && s[R] - s[L - 1] - sd[q.back()] > p) {
            L++;
            while (!q.empty() && q.back() - L + 1 < d) q.pop_back();
        }
        ans = max(ans,R - L + 1);
    }
    cout << ans << endl;
    return 0;
}