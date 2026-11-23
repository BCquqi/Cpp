#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 5e4 + 5;
struct Question {int l,r,id;} q[N];
struct Answer {long long a,b; int id;} ans[N];
struct Block {int l,r;} block[N];
int n,m,c[N],pos[N],cnt[N];
long long sum = 0;

void init() {
    int len = (int) sqrt(n), block_num = (n + len - 1) / len;
    for (int i = 1;i <= n;i++) pos[i] = (i - 1) / len + 1;
    for (int i = 1;i <= block_num;i++)
        block[i].l = (i - 1) * len + 1, block[i].r = min(i * len,n);
    return ;
}

inline void modify(int x,int y) {
    sum -= cnt[c[x]] * cnt[c[x]];
    cnt[c[x]] += y;
    sum += cnt[c[x]] * cnt[c[x]];
}

void solve() {
    for (int i = 1,l = 1,r = 0;i <= m;i++) {
        ans[i].id = q[i].id;
        for (;r > q[i].r;r--) modify(r,-1);
        for (;r < q[i].r;r++) modify(r + 1,1);
        for (;l < q[i].l;l++) modify(l,-1);
        for (;l > q[i].l;l--) modify(l - 1,1);
        if (q[i].l == q[i].r) {
            ans[i].a = 0, ans[i].b = 1;
            continue;
        }
        int len = q[i].r - q[i].l + 1;
        ans[i].a = sum - len, ans[i].b = 1ll * len * (len - 1);
        long long gcd = __gcd(ans[i].a,ans[i].b);
        ans[i].a /= gcd, ans[i].b /= gcd;
    }
    return ;
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> c[i];
    init();
    for (int i = 1;i <= m;i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1,q + m + 1,[](Question x,Question y) {return pos[x.l] != pos[y.l] ? x.l < y.l : x.r < y.r;});
    solve();
    sort(ans + 1,ans + m + 1,[](Answer x,Answer y) {return x.id < y.id;});
    for (int i = 1;i <= m;i++) cout << ans[i].a << '/' << ans[i].b << endl;
    return 0;
}