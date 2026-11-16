#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

const int N = 1e5 + 5,M = 35;
int T,n,lim,p;
char s[N][M];
int a[N],pre[N],id[N];
long double sum[N],dp[N];
struct Node {int l,r,j;} q[N << 1];
int h,cur;

inline long double qpow(long double a,int b) {
    long double res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    cin >> n >> lim >> p;
    for (int i = 1;i <= n;i++) {
        cin >> s[i];
        a[i] = strlen(s[i]);
        sum[i] = sum[i - 1] + a[i] + 1;
    }
    dp[0] = 0, h = 1, cur = 0, q[++cur] = {1,n,0};
    for (int i = 1;i <= n;i++) {
        while (h <= cur && q[h].r < i) h++;
        int j = q[h].j;
        dp[i] = dp[j] + qpow(fabsl(sum[i] - sum[j] - 1 - lim),p);
        pre[i] = j;
        while (h <= cur && dp[i] + qpow(fabsl(sum[q[cur].l] - sum[i] - 1 - lim),p) < dp[q[cur].j] + qpow(fabsl(sum[q[cur].l] - sum[q[cur].j] - 1 - lim),p)) cur--;
        if (h > cur) q[++cur] = {i + 1,n,i};
        else {
            int l = q[cur].l,r = q[cur].r,ans = r + 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (dp[i] + qpow(fabsl(sum[mid] - sum[i] - 1 - lim),p) < dp[q[cur].j] + qpow(fabsl(sum[mid] - sum[q[cur].j] - 1 - lim),p))
                    ans = mid, r = mid - 1;
                else l = mid + 1;
            }
            if (ans <= n)
                q[cur].r = ans - 1, q[++cur] = {ans,n,i};
        }
    }
    if (dp[n] > 1e18)
        cout << "Too hard to arrange" << endl;
    else {
        cout << (long long)dp[n] << endl;
        int cnt = 0,lst = 0;
        for (int i = n;i > 0;i = pre[i]) id[++cnt] = i;
        for (int i = cnt;i >= 1;i--) {
            int pos = id[i];
            for (int j = lst + 1;j <= pos;j++) {
                if (j != lst + 1) cout << ' ';
                cout << s[j];
            }
            cout << endl;
            lst = pos;
        }
    }
    cout << "--------------------" << endl;
    return ;
}

int main() {
    cin >> T;
    while (T--) solve();
    return 0;
}