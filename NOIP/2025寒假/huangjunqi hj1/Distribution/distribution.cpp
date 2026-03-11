#include<iostream>
using namespace std;

const int N = 2e5 + 5;
int s[N],t[N],ans[N];

int main() {
    int n,mint = 1e9,start = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> s[i];
    for (int i = 1;i <= n;i++) {
        cin >> t[i];
        if (t[i] < mint) mint = t[i],start = i;
    }
    ans[start] = t[start];
    for (int i = start + 1;i <= start + n;i++) {
        int cur = i > n ? i - n : i;
        int last = cur == 1 ? n : cur - 1;
        ans[cur] = min(t[cur],ans[last] + s[last]);
    }
    for (int i = 1;i <= n;i++) cout << ans[i] << endl;
    return 0;
}