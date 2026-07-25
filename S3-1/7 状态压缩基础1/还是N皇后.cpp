#include<iostream>
using namespace std;

const int N = 20;
int n,ans = 0;
char c[N][N];

void dfs(int step,int col,int lr,int rl) {
    if (step >= n) {
        ans++;
        return ;
    }
    for (int i = 0;i < n;i++) {
        if (c[step][i] == '*' && !((col >> i) & 1) && !((lr >> i) & 1) && !((rl >> i) & 1))
            dfs(step + 1,col | (1 << i),(lr | (1 << i)) << 1,(rl | (1 << i)) >> 1);
    }
}

int main() {
    cin >> n;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++) cin >> c[i][j];
    dfs(0,0,0,0);
    cout << ans << endl;
    return 0;
}

/*
Better Version: 
#include<iostream>
#include<cmath>
using namespace std;

const int N = 20;
int n,ans = 0;
char c[N][N];

void dfs(int step,int col,int lr,int rl) {
    if (step >= n) {
        ans++;
        return ;
    }
    int t = col | lr | rl;
    t = ~t;
    t &= ((1 << n) - 1);
    while (t) {
        int i = t & -t;
        t -= i;
        if (c[step][int(log2(i))] == '.') continue;
        dfs(step + 1,col | i,(lr | i) << 1,(rl | i) >> 1);
    }
}

int main() {
    cin >> n;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++) cin >> c[i][j];
    dfs(0,0,0,0);
    cout << ans << endl;
    return 0;
}
*/