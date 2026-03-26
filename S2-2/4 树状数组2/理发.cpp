#include<iostream>
using namespace std;

const int N = 1e5 + 5;
long long a[N],b[N],c[N],d[N],ans[N],n;

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
        a[i]++;
        change(a[i],1);
        long long s = i - sum(a[i]);
        d[a[i]] += s;
    }
    for (int i = 1;i < n;i++) ans[i] = ans[i - 1] + d[i];
    for (int i = 0;i < n;i++) cout << ans[i] << endl;
    return 0;
}