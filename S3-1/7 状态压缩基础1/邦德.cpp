/*
95 pts:
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

const int N = 25;
int a[N][N],n;
double ans = 0.00;

void dfs(int step,int col,double m) {
    if (m < ans) return ;
    if (step >= n) {
        ans = max(ans,m);
        return ;
    }
    int t = ~col;
    t &= (1 << n) - 1;
    while (t) {
        int x = t & -t;
        t -= x;
        dfs(step + 1,col | x,m * a[step][__lg(x)] / 100.0);
    }
}

int main() {
    cin >> n;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            scanf("%d",&a[i][j]);
    dfs(0,0,100.00);
    printf("%.6lf\n",ans);
    return 0;
}
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

const int N = 25;
int a[N][N],n;
double dp[(1 << 20) + 5];

int main() {
    cin >> n;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            scanf("%d",&a[i][j]);
    dp[0] = 100;
    for (int i = 0;i < (1 << n);i++) {
        int x = -1;
        for (int j = 0;j < n;j++)
            if ((i >> j) & 1) x++;
        for (int j = 0;j < n;j++)
            if (((i >> j) % 1) == 0)
                dp[i | (1 << j)] = max(dp[i | (1 << j)],dp[i] * a[j][x + 1] / 100.0);
    }
    printf("%.6lf\n",dp[(1 << n) - 1]);
    return 0;
}