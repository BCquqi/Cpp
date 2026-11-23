#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 4005;
short u[N][N];
int s[N][N];
long long dp[805][N];

inline int query(int l,int r)
{return (s[r][r] - s[l - 1][r] - s[r][l - 1] + s[l - 1][l - 1]) / 2;}

void merge(int i,int l,int r,int optl,int optr) {
    if (l > r) return ;
    int mid = (l + r) >> 1;
    long long mx = 1e18;
    int id = 0;
    for (int j = optl;j <= min(optr,mid - 1);j++) {
        long long val = dp[i - 1][j] + query(j + 1,mid);
        if (val < mx)
            mx = val, id = j;
    }
    dp[i][mid] = mx;
    merge(i,l,mid - 1,optl,id), 
    merge(i,mid + 1,r,id,optr);
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) {
            cin >> u[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + u[i][j];
        }
    memset(dp,0x3f,sizeof dp);
    dp[0][0] = 0;
    for (int i = 1;i <= k;i++)
        merge(i,i,n,i - 1,n - 1);
    cout << dp[k][n] << '\n';
    return 0;
}