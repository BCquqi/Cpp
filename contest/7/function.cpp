#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
struct Node {int x,y;} s[N];
int n;
double tmp[N];

long long check(double mid) {
    for (int i = 1;i <= n;i++) tmp[i] = 0;
    for (int i = 1;i <= n;i++) tmp[i] = s[i].x * (s[i].y - mid);
    sort(tmp + 1,tmp + n + 1);
    int l = 1,r = n; // l 指向最小，r 指向最大
    long long ret = 0;
    while (l < r) {
        if (tmp[l] + tmp[r] < 0) ret += r - l,l++; // 最小的都可以和最大的配对，剩下也可以
        else r--;
    }
    return ret;
}

int main() {
    freopen("function.in","r",stdin);
    freopen("function.out","w",stdout);
    long long k;
    scanf("%d%lld",&n,&k);
    double l = 0,r = 1e9;
    for (int i = 1;i <= n;i++) {
        scanf("%d%d",&s[i].x,&s[i].y);
        l = min(l,1.0 * s[i].y), r = max(r,1.0 * s[i].y);
    }
    while (r - l > 1e-6) {
        double mid = (l + r) / 2;
        if (check(mid) < 1ll * n * (n - 1) / 2 - k + 1) l = mid;
        else r = mid;
    }
    printf("%.6lf\n",l);
    return 0;
}