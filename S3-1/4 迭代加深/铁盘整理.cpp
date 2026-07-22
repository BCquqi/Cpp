#include<iostream>
#include<algorithm>
using namespace std;

const int N = 20;
int a[N],r[N],m,n,ans = 1e9;
bool flag;

int evaluate() {
    int s = 0;
    for (int i = 1;i <= n;i++)
        if (abs(a[i] - a[i + 1]) != 1) s++;
    return s;
}

void dfs(int cnt) {
    int d = evaluate();
    if (d == 0) flag = true,ans = min(ans,cnt);
    if (flag) return ;
    if (cnt + d > m) return ;
    for (int i = 2;i <= n;i++) {
        reverse(a + 1,a + i + 1);
        dfs(cnt + 1);
        reverse(a + 1,a + i + 1);
    }
}

int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        r[i] = a[i];
    }
    sort(r + 1,r + n + 1);
    for (int i = 1;i <= n;i++)
        a[i] = lower_bound(r + 1,r + n + 1,a[i]) - r;
    a[n + 1] = n + 1;
    for (m = evaluate(); ;m++) {
        dfs(0);
        if (flag) break;
    }
    cout << ans << endl;
    return 0;
}