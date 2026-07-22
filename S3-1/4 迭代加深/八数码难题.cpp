#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

const int N = 5;
int a[N][N],m,X,Y,ans = 1e9;
int dx[] = {0,0,-1,1},dy[] = {-1,1,0,0};
bool flag;

int e[9][2] = {{2,2},{1,1},{1,2},{1,3},{2,3},{3,3},{3,2},{3,1},{2,1}};

int evaluate() {
    int s = 0;
    for (int i = 1;i <= 3;i++)
        for (int j = 1;j <= 3;j++)
            s += abs(e[a[i][j]][0] - i) + abs(e[a[i][j]][1] - j);
    return s;
}

void sep(int n) {
    for (int i = 3;i >= 1;i--)
        for (int j = 3;j >= 1;j--) {
            a[i][j] = n % 10,n /= 10;
            if (a[i][j] == 0) X = i,Y = j;
        }
}

int merge() {
    int ret = 0;
    for (int i = 1;i <= 3;i++)
        for (int j = 1;j <= 3;j++)
            ret = ret * 10 + a[i][j];
    return ret;
}

void dfs(int x,int y,int cnt) {
    int d = evaluate();
    if (d == 0) flag = true,ans = min(ans,cnt);
    if (flag) return ;
    if (cnt + d > m) return ;
    for (int i = 0;i <= 3;i++) {
        int nx = x + dx[i],ny = y + dy[i];
        if (nx < 1 || ny < 1 || nx > 3 || ny > 3) continue;
        swap(a[x][y],a[nx][ny]);
        dfs(nx,ny,cnt + 1);
        swap(a[x][y],a[nx][ny]);
    }
}

int main() {
    int n;
    cin >> n;
    sep(n);
    for (m = evaluate(); ;m++) {
        dfs(X,Y,0);
        if (flag) break;
    }
    cout << ans << endl;
    return 0;
}