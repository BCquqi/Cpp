#include<iostream>
#define int long long
using namespace std;

const int N = 4100;
int n,m,tree[N][N];

int lowbit(int x) {return x & -x;}
void add(int x,int y,int val) {
    for (int i = x;i <= n;i += lowbit(i))
        for (int j = y;j <= m;j += lowbit(j))
            tree[i][j] += val;
}
long long query(int x,int y) {
    long long ret = 0;
    for (int i = x;i > 0;i -= lowbit(i))
        for (int j = y;j > 0;j -= lowbit(j))
            ret += tree[i][j];
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int op;
    while (cin >> op) {
        if (op == 1) {
            int a,b,c,d,k;
            cin >> a >> b >> c >> d >> k;
            add(a,b,k);
            if (d + 1 <= m) add(a,d + 1,-k);
            if (c + 1 <= n) add(c + 1,b,-k);
            if (d + 1 <= m && c + 1 <= n) add(c + 1,d + 1,k);
        } else {
            int x,y;
            cin >> x >> y;
            cout << query(x,y) << '\n';
        }
    }
    return 0;
}