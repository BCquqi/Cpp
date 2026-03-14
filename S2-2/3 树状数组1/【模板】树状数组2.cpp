#include<iostream>
using namespace std;

const int N = 5e5 + 5;
long long a[N],c[N],n,m;

int lowbit(int x) {return x & -x;}
void change(int x,int t) {while (x <= n) c[x] += t,x += lowbit(x);}
long long sum(int x) {
    long long ans = 0;
    while (x > 0) ans += c[x],x -= lowbit(x);
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        change(i,a[i] - a[i - 1]);
    }
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x,y,k;
            cin >> x >> y >> k;
            change(x,k); change(y + 1,-k);
        }
        else {
            int x;
            cin >> x;
            cout << sum(x) << endl;
        }
    }
    return 0;
}