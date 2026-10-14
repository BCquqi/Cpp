#include<iostream>
#include<cstring>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int c[N],num[N];

void solve() {
    memset(num,0,sizeof num);
    int n,m;
    cin >> n >> m;
    int cnt = 1,diff = 0,maxnum = 0; // diff 记录有多少物品被排挤
    for (int i = 1;i <= n * m;i++) {
        cin >> c[i];
        if (c[i] == c[i - 1]) cnt++;
        else 
            diff += cnt / 2, num[c[i - 1]] += cnt / 2, maxnum = max(maxnum,num[c[i - 1]]), cnt = 1; // 连续段则至少要有 cnt / 2 个被驱逐
    }
    diff += cnt / 2, num[c[n * m]] += cnt / 2, maxnum = max(maxnum,num[c[n * m]]), cnt = 1; // 最后一组
    int ans = n * m - diff;
    if (maxnum >= diff - maxnum) // 如果有一个被驱逐数量比总量大，则其会排挤其他正确的
        ans -= maxnum - (diff - maxnum);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("parrot.in","r",stdin);
    freopen("parrot.out","w",stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}