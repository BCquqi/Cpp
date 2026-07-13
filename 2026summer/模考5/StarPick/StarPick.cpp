#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 20;
int a[N][N],plan[2 * N];
// dp 数组代表现在在几行几列，选过几个的最大信号值总和

void dfs(int step,int x,int y) {
    for ()
    if (x < n) {
        plan[step] = 1;
        dfs(x + 1,y);
        plan[step] = 0;
    }
    if (y < n) {
        plan[step] = 2;
        dfs(x,y + 1);
        plan[step] = 0;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i][j];
    dfs(1,1,1);
    return 0;
}