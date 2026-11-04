#include<iostream>
#include<cmath>
using namespace std;

const int N = 2e6 + 5;
bool vis[N];

int main() {
    int lim = 2e6;
    memset(vis,false,sizeof vis);
    vis[1] = true;
    for (int i = 2;i <= lim;i++) {
        if (vis[i]) continue;
        for (int j = 2;i * j <= lim;j++)
            vis[i * j] = true;
    }
    int ans = 0;
    for (int i = 1;i <= lim;i++)
        if (!vis[i]) ans++;
    cout << ans << endl;
    return 0;
}