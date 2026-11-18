#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 2e6 + 5;
struct Query {int op,t,x,y,k;} a[N];
int pos[N],cur = 0,n;
int ice[N],fire[N];

int lowbit(int x) {return x & -x;}
void add(int id,int val,int tree[]) {while (id <= n) tree[id] += val,id += lowbit(id);}
int query(int id,int tree[]) {
    int ret = 0;
    while (id) ret += tree[id],id -= lowbit(id);
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int q;
    cin >> q;
    for (int i = 1;i <= q;i++) {
        cin >> a[i].op;
        if (a[i].op == 1) {
            cin >> a[i].t >> a[i].x >> a[i].y;
            pos[++cur] = a[i].x;
        } else cin >> a[i].k;
    }
    sort(pos + 1,pos + cur + 1);
    n = unique(pos + 1,pos + cur + 1) - pos - 1;
    int sum = 0;
    for (int i = 1;i <= q;i++) {
        if (a[i].op == 1) {
            a[i].x = lower_bound(pos + 1,pos + n + 1,a[i].x) - pos;
            if (a[i].t == 0) add(a[i].x,a[i].y,ice);
            else add(a[i].x + 1,a[i].y,fire), sum += a[i].y;
        } else {
            if (a[a[i].k].t == 0) add(a[a[i].k].x,-a[a[i].k].y,ice);
            else add(a[a[i].k].x + 1,-a[a[i].k].y,fire), sum -= a[a[i].k].y;
        }
        int pos1 = 0,pos2 = 0,ans1 = 0,ans2 = 0,sum1 = 0,sum2 = sum;
        for (int j = 20;j >= 0;j--) {
            int now = pos1 + (1 << j);
            if (now > n) continue;
            int tmp1 = sum1 + ice[now],tmp2 = sum2 - fire[now];
            if (tmp1 < tmp2) pos1 = now, sum1 = tmp1, sum2 = tmp2;
        }
        ans1 = sum1;
        if (pos1 < n) {
            ans2 = min(query(pos1 + 1,ice),sum - query(pos1 + 1,fire));
            sum1 = 0, sum2 = sum; 
            for (int j = 20;j >= 0;j--) {
                int now = pos2 + (1 << j);
                if (now > n) continue;
                int tmp1 = sum1 + ice[now],tmp2 = sum2 - fire[now];
                if (tmp1 < tmp2 || min(tmp1,tmp2) == ans2) pos2 = now, sum1 = tmp1, sum2 = tmp2;
            }
        }
        if (max(ans1,ans2) == 0) cout << "Peace" << '\n';
        else if (ans1 > ans2) cout << pos[pos1] << ' ' << 2 * ans1 << '\n';
        else cout << pos[pos2] << ' ' << 2 * ans2 << '\n';
    }
    return 0;
}