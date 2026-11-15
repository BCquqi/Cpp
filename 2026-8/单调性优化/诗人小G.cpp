#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int n, L, p;
int sum[N], last[N], nxt[N], q[N];
long double f[N];
char s[N][35];
struct Node {int l, r;} seg[N];

inline long double qpow(int x) {
    if (!x) return 0;
    long double a = x, res = 1;
    for (int b = p;b;b >>= 1) {
        if (b & 1) res = res * a;
        a = a * a;
    }
    return res;
}

inline long double calc(int i,int j) {
    return f[j] + qpow(abs(sum[i] - sum[j] - 1 - L));
}

void solve() {
    cin >> n >> L >> p;
    for (int i = 1;i <= n;i++) {
        cin >> s[i];
        sum[i] = sum[i - 1] + strlen(s[i]) + 1;
    }
    
    int head = 1, tail = 1;
    q[1] = 0, seg[0].l = 1, seg[0].r = n;
    
    for (int i = 1;i <= n;i++) {
        while (seg[q[head]].r < i) head++;
        f[i] = calc(i, q[head]);
        last[i] = q[head];
        seg[q[head]].l++;
        
        if (calc(n, q[tail]) <= calc(n, i)) continue;
        
        while (head < tail && calc(seg[q[tail]].l, q[tail]) >= calc(seg[q[tail]].l, i)) tail--;
        
        int l = seg[q[tail]].l, r = seg[q[tail]].r, pos = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (calc(mid, q[tail]) >= calc(mid, i)) pos = mid, r = mid - 1;
            else l = mid + 1;
        }
        if (pos == -1) continue;
        seg[q[tail]].r = pos - 1;
        q[++tail] = i, seg[i].l = pos, seg[i].r = n;
    }
    
    if (f[n] > 1e18) {
        cout << "Too hard to arrange" << endl;
    } else {
        cout << (long long)(f[n] + 0.5) << endl;
        int tmp = n;
        while (tmp) {
            nxt[last[tmp]] = tmp;
            tmp = last[tmp];
        }
        tmp = 0;
        while (tmp != n) {
            for (int i = tmp + 1;i <= nxt[tmp];i++) {
                cout << s[i];
                if (i != nxt[tmp]) cout << ' ';
            }
            cout << endl;
            tmp = nxt[tmp];
        }
    }
    cout << "--------------------" << endl;
    return ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}