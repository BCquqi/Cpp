#include<iostream>
using namespace std;

const int N = 105;
int n,m,a[N];
bool flag;

void dfs(int step) {
    if (a[step - 1] * (1 << (m - step + 1)) < n) return ;
    if (flag) return ;
    if (step > m) {
        if (a[step - 1] == n) {
            flag = true;
            for (int i = 0;i <= m;i++) cout << a[i] << ' ';
            cout << endl;
        }
        return ;
    }
    for (int i = 0;i < step;i++)
        for (int j = i;j < step;j++) {
            a[step] = a[i] + a[j];
            if (a[step] <= a[step - 1]) continue;
            if (a[step] > n) break;
            dfs(step + 1);
        }
}

void solve() {
	flag = false,a[0] = 1;
    for (m = 0; ;m++) {
        dfs(1);
        if (flag) break;
    }
    return ;
}

int main() {
    while (true) {
        cin >> n;
        if (n == 0) break;
        solve();
    }
    return 0;
}