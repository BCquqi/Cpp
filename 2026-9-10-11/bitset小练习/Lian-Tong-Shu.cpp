#include<iostream>
#include<bitset>
using namespace std;

const int N = 2005;
bitset<N> G[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) {
            char c;
            cin >> c;
            G[i][j] = (c == '1');
        }
    for (int i = 1;i <= n;i++) G[i][i] = true;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            if (G[j][i]) G[j] |= G[i];
    int ans = 0;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            ans += G[i][j];
    cout << ans << endl;
    return 0;
}