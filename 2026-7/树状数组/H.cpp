#include<iostream>
using namespace std;

const int N = 4100;
int n,m;
long long tree[N][N];

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int op;
    while (cin >> op) {
        if (op == 1) {
            int x,y,k;
            cin >> x >> y >> k;
            add(x,y,k);
        } else {
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            cout << 1ll * query(a - 1,b - 1) - query(a - 1,d) - query(c,b - 1) + query(c,d) << '\n';
        }
    }
    return 0;
}