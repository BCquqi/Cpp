#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1e6 + 5;
int n,label[N];

void solve() {
    cin >> n;
    int u = 0;
    for (int i = 1;i <= n;i++) {
        cin >> label[i];
        if (label[i] == -1) u++;
    }
    cout << "POSSIBLE" << '\n';
    return ;
}

int main() {
    freopen("thread.in","r",stdin);
    freopen("thread.out","w",stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}