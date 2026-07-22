#include<iostream>
using namespace std;

const int N = 10;
int m,ans = 1e9;
int dx[] = {-2,-1,-2,-1,2,1,2,1},dy[] = {-1,-2,1,2,-1,-2,1,2};
char c[N][N],e[7][7] = {""," 11111"," 01111"," 00*11"," 00001"," 00000"};
bool flag;

int evaluate() {
    int s = 0;
    for (int i = 1;i <= 5;i++)
        for (int j = 1;j <= 5;j++) {
            if (c[i][j] == '*') continue;
            if (c[i][j] != e[i][j]) s++;
        }
    return s;
}

void dfs(int x,int y,int cnt) {
    int d = evaluate();
    if (d == 0) flag = true,ans = min(ans,cnt);
    if (flag) return ;
    if (cnt + d > m) return ;
    for (int i = 0;i <= 7;i++) {
        int nx = x + dx[i],ny = y + dy[i];
        if (nx < 1 || ny < 1 || nx > 5 || ny > 5) continue;
        swap(c[x][y],c[nx][ny]);
        dfs(nx,ny,cnt + 1);
        swap(c[x][y],c[nx][ny]);
    }
}

void solve() {
    int X,Y;
    flag = 0,ans = 1e9;
    for (int i = 1;i <= 5;i++)
        for (int j = 1;j <= 5;j++) {
            cin >> c[i][j];
            if (c[i][j] == '*') X = i,Y = j;
        }
    for (m = evaluate();m <= 15;m++) {
        dfs(X,Y,0);
        if (flag) break;
    }
    cout << (ans == 1e9 ? -1 : ans) << endl;
    return ;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}