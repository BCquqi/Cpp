/*
赛后反思

本题想了很多种解题方法，但总会在时间复杂度、空间复杂度或后效性上出问题，导致卡了几乎一个多小时影响T3T4做题时间，比较可惜。
1. 最先想到贪心，根据题目数据的50pts无后效性保证，不能拿满；
2. 想到bfs，时间复杂度充裕但需要利用位值原理拼接字符串，dis数组开LL也不够；
3. 使用dp需要开二维string数组，但数组不优化情况下复杂度O(n^3)，考场上没有想到滚动数组或者一维优化；
4. 本题使用数学思维推出每一步进行递推操作即可，不用那么复杂。
*/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 2005;
char a[N][N];
bool vis[N][N];

int main() {
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    int n,m;
    cin >> n >> m;
    memset(a,127,sizeof a);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            cin >> a[i][j];
    cout << a[1][1];
    vis[1][1] = true;
    for (int i = 2;i <= n + m - 1;i++) {
        char c = 127;
        for (int x = 1;x <= n;x++) {
            int y = i - x + 1;
            if (y < 1 || y > m) continue;
            if (vis[x - 1][y] || vis[x][y - 1])
                c = min(c,a[x][y]);
        }
        cout << c;
        for (int x = 1;x <= n;x++) {
            int y = i - x + 1;
            if (y < 1 || y > m) continue;
            if ((vis[x - 1][y] || vis[x][y - 1]) && a[x][y] == c)
                vis[x][y] = true;
        }
    }
    cout << endl;
    return 0;
}