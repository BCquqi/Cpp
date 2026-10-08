#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

const int N = 1e5 + 5;
const double eps = 1e-6;
int n,q[N],id[N];
double s,dp[N];

struct Node {double a,b,rate,ca,cb,k;} x[N];

void cdq(int l,int r) {
    if (l == r) {
        dp[l] = max(dp[l],dp[l - 1]);
        x[l].cb = dp[l] / (x[l].a * x[l].rate + x[l].b), x[l].ca = x[l].cb * x[l].rate;
        return;
    }
    int mid = (l + r) >> 1;
    cdq(l,mid);
    for (int i = l;i <= r;i++) id[i] = i;
    sort(id + l,id + mid + 1,[](int u, int v) {return x[u].ca < x[v].ca;});
    sort(id + mid + 1,id + r + 1,[](int u, int v) {return x[u].k > x[v].k;});
    int head = 0,tail = 0;
    for (int i = l;i <= mid;i++) {
        int c = id[i];
        while (head < tail && (x[q[tail]].cb - x[q[tail - 1]].cb) * (x[c].ca - x[q[tail]].ca) <= (x[c].cb - x[q[tail]].cb) * (x[q[tail]].ca - x[q[tail - 1]].ca) + eps) tail--;
        q[++tail] = c;
    }
    for (int i = mid + 1;i <= r;i++) {
        int j = id[i];
        while (head < tail && (x[q[head + 1]].cb - x[q[head]].cb) >= x[j].k * (x[q[head + 1]].ca - x[q[head]].ca) - eps) head++;
        dp[j] = max(dp[j],x[j].a * x[q[head]].ca + x[j].b * x[q[head]].cb);
    }
    cdq(mid + 1,r);
}

int main() {
    cin >> n >> s;
    for (int i = 1;i <= n;i++) {
        cin >> x[i].a >> x[i].b >> x[i].rate;
        x[i].k = -x[i].a / x[i].b, dp[i] = s;
    }
    cdq(1,n);
    cout << fixed << setprecision(3) << dp[n] << endl;
    return 0;
}