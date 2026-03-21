#include<iostream>
using namespace std;

const int N = 5e5 + 5;
long long a[N],c1[N],c2[N],n,m;

long long lowbit(long long x) {return x & -x;}
void change(long long x,long long t,long long c[]) {while (x <= n) c[x] += t,x += lowbit(x);}
long long sum(long long x,long long c[]) {
    long long ans = 0;
    while (x > 0) ans += c[x],x -= lowbit(x);
    return ans;
}
long long query(long long x) {return 1ll * x * sum(x,c1) - sum(x,c2);}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        change(i,a[i] - a[i - 1],c1);
        change(i,(i - 1) * (a[i] - a[i - 1]),c2);
    }
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x,y,k;
            cin >> x >> y >> k;
            change(x,k,c1); change(y + 1,-k,c1);
            change(x,1ll * x * k - k,c2); change(y + 1,1ll *-y * k,c2);
        } else {
            int x,y;
            cin >> x >> y;
            cout << query(y) - query(x - 1) << endl;
        }
    }
    return 0;
}