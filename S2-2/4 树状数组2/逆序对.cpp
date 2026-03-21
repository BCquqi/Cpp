#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5e5 + 5;
int a[N],b[N],c[N],n;

long long lowbit(long long x) {return x & -x;}
void change(long long x,long long t) {while (x <= n) c[x] += t,x += lowbit(x);}
long long sum(long long x) {
    long long ans = 0;
    while (x > 0) ans += c[x],x -= lowbit(x);
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1,b + n + 1);
    int m = unique(b + 1,b + n + 1) - b - 1;
    long long ans = 0;
    for (int i = 1;i <= n;i++) {
        a[i] = lower_bound(b + 1,b + m + 1,a[i]) - b;
        change(a[i],1);
        ans += i - sum(a[i]);
    }
    cout << ans << endl;
    return 0;
}