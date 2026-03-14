#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int t1[N],t2[N],n,m;

int lowbit(int x) {return x & -x;}
void change(int c[N],int x,int t) {while (x <= n) c[x] += t,x += lowbit(x);}
long long sum(int c[N],int x) {
    long long ans = 0;
    while (x > 0) ans += c[x],x -= lowbit(x);
    return ans;
}

int main() {
    cin >> n >> m;
    while (m--) {
        int q,l,r;
        cin >> q >> l >> r;
        if (q == 1) {
            change(t1,l,1);
            change(t2,r,1);
        }
        else cout << sum(t1,r) - sum(t2,l - 1) << endl;
    }
    return 0;
}