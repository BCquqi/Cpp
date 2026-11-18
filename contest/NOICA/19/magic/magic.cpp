#include<iostream>
#include<string>
using namespace std;
#define int long long

const int N = 1e3 + 5,M = 1e6 + 5;
int n,m,sum = 0;
int w[N][N];

struct Node {int x,y;} path[M];

void init(int &cur) {
    for (int j = m;j >= 1;j--) path[++cur] = {1,j};
    for (int i = 2;i <= n;i++) path[++cur] = {i,1};
    for (int j = 2;j <= m;j++) {
        if (j % 2 == 0)
            for (int i = n;i >= 2;i--)
                path[++cur] = {i,j};
        else 
            for (int i = 2;i <= n;i++)
                path[++cur] = {i,j};
    }
    return ;
}

void solve() {
    cin >> n >> m;
    sum = 0;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            cin >> w[i][j], sum += w[i][j];
    if (sum < 0) {
        cout << "No" << endl;
        return ;
    }
    int cur = 0;
    init(cur);
    int now = 0,mn = 1e18,pos = 0;
    for (int i = 1;i <= cur;i++) {
        now += w[path[i].x][path[i].y];
        if (now < mn) mn = now, pos = i;
    }
    int st = pos + 1;
    if (st > cur) st = 1;
    cout << "Yes" << endl;
    cout << path[st].x << ' ' << path[st].y << endl;
    string s;
    for (int i = 0;i < cur - 1;i++) {
        int u = (st + i - 1) % cur + 1;
        int v = (st + i) % cur + 1;
        int x1 = path[u].x,y1 = path[u].y;
        int x2 = path[v].x,y2 = path[v].y;
        if (x2 < x1) s += 'U';
        else if (x2 > x1) s += 'D';
        else if (y2 < y1) s += 'L';
        else if (y2 > y1) s += 'R';
    }
    cout << s << endl;
    return ;
}

signed main() {
    freopen("magic.in","r",stdin);
    freopen("magic.out","w",stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
