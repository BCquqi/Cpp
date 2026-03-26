#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
long long n,l,r,a[N],s[N],ss[N * 3],cur = 0,c[N * 3],m,ans = 0;

long long lowbit(long long x) {return x & -x;}
void change(long long x,long long t) {while (x <= m) c[x] += t,x += lowbit(x);}
long long sum(long long x) {
    long long ans = 0;
    while (x > 0) ans += c[x],x -= lowbit(x);
    return ans;
}

int main() {
    cin >> n >> l >> r;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        ss[++cur] = s[i];
        ss[++cur] = s[i] - l;
        ss[++cur] = s[i] - r;
    }
    ss[++cur] = 0;
    sort(ss + 1,ss + cur + 1);
    m = unique(ss + 1,ss + cur + 1) - ss - 1;
    change(lower_bound(ss + 1,ss + m + 1,0) - ss,1);
    for (int j = 1;j <= n;j++) {
        int L = lower_bound(ss + 1,ss + m + 1,s[j] - r) - ss;
        int R = lower_bound(ss + 1,ss + m + 1,s[j] - l) - ss;
        ans += sum(R) - sum(L - 1);
        change(lower_bound(ss + 1,ss + m + 1,s[j]) - ss,1);
    }
    cout << ans << endl;
    return 0;
}