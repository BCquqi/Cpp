#include<iostream>
#include<deque>
#include<cstdio>
using namespace std;

const int N = 1e5 + 5;
const double eps = 1e-6;
int a[N],n,S,T;
double l = -1e4,r = 1e4,s[N];

bool check(double x) {
    for (int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i] - x;
    deque<int> q; // q 维护可选左端点的最小值
    for (int i = S;i <= n;i++) { // 枚举右端点，则左端点最多就是 i - S
        while (!q.empty() && q.front() + T < i) q.pop_front();
        while (!q.empty() && s[q.back()] >= s[i - S]) q.pop_back();
        q.push_back(i - S);
        if (!q.empty() && s[i] - s[q.front()] >= 0) return true;
    }
    return false;
}

int main() {
    double ans = -1e9;
    cin >> n >> S >> T;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        l = min((double)a[i],l);
        r = max((double)a[i],r);
    }
    while (r - l > eps) {
        double mid = (l + r) / 2.00;
        if (check(mid)) l = mid,ans = mid;
        else r = mid;
    }
    printf("%.3lf\n",ans);
    return 0;
}