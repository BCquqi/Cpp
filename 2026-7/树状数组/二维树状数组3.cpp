#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 2050;
int n,m;

int lowbit(int x) {return x & -x;}

struct Node {
    int tree[N][N];
    void add(int x,int y,int val) {
        for (int i = x;i <= n;i += lowbit(i))
            for (int j = y;j <= m;j += lowbit(j))
                tree[i][j] += val;
    }
    int query(int x,int y) {
        long long ret = 0;
        for (int i = x;i > 0;i -= lowbit(i))
            for (int j = y;j > 0;j -= lowbit(j))
                ret += tree[i][j];
        return ret;
    }
} a,b,c,d;

void modify(int x,int y,int k) {
    a.add(x,y,k);
    b.add(x,y,k * x);
    c.add(x,y,k * y);
    d.add(x,y,k * x * y);
}

void change(int x1,int y1,int x2,int y2,int k) {
    modify(x1,y1,k);
    modify(x1,y2 + 1,-k);
    modify(x2 + 1,y1,-k);
    modify(x2 + 1,y2 + 1,k);
}

int sum(int x,int y) {
    int ret = (1ll * x * y + x + y + 1) * a.query(x,y);
    ret -= 1ll * (y + 1) * b.query(x,y);
    ret -= 1ll * (x + 1) * c.query(x,y);
    ret += d.query(x,y);
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int op;
    while (cin >> op) {
        if (op == 1) {
            int A,B,C,D,x;
            cin >> A >> B >> C >> D >> x;
            change(A,B,C,D,x);
        } else {
            int A,B,C,D;
            cin >> A >> B >> C >> D;
            cout << sum(C,D) - sum(A - 1,D) - sum(C,B - 1) + sum(A - 1,B - 1) << '\n';
        }
    }
    return 0;
}