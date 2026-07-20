#include<iostream>
#include<cstdio>
using namespace std;

const int N = 55;
char a[N][N];

int main() {
    // freopen("snow.in","r",stdin);
    // freopen("snow.out","w",stdout);
    int n,m,ans = 0;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            cin >> a[i][j];
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) {
            if (a[i][j] != '+') continue;
            int x = i,y = j,cnt = 0,siz = 1e9;
            while (a[x][++y] == '-') cnt++;
            x = i,y = j,siz = min(siz,cnt),cnt = 0;
            while (a[x][--y] == '-') cnt++;
            x = i,y = j,siz = min(siz,cnt),cnt = 0;
            while (a[++x][y] == '|') cnt++;
            x = i,y = j,siz = min(siz,cnt),cnt = 0;
            while (a[--x][y] == '|') cnt++;
            x = i,y = j,siz = min(siz,cnt),cnt = 0;
            while (a[++x][++y] == '\\') cnt++;
            x = i,y = j,siz = min(siz,cnt),cnt = 0;
            while (a[++x][--y] == '/') cnt++;
            x = i,y = j,siz = min(siz,cnt),cnt = 0;
            while (a[--x][++y] == '/') cnt++;
            x = i,y = j,siz = min(siz,cnt),cnt = 0;
            while (a[--x][--y] == '\\') cnt++;
            x = i,y = j,siz = min(siz,cnt),cnt = 0;
            ans = max(ans,siz);
        }
    cout << ans << endl;
    return 0;
}