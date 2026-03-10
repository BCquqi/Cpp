#include<iostream>
using namespace std;

const int N = 205;
bool G[N][N];

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x,y;
        cin >> x >> y;
        G[x][y] = true;
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) cout << G[i][j] << ' ';
        cout << endl;
    }
    return 0;
}