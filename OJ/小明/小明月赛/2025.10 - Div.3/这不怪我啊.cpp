#include<iostream>
#include<cstring>
using namespace std;

const int N = 1005;
int a[N];
bool flag[N];

void solve(int pos) {
    if (flag[pos]) {cout << pos << ' '; return ;}
    flag[pos] = true;
    solve(a[pos]);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) {
        memset(flag, 0, sizeof flag);
        solve(i);
    }
    return 0;
}