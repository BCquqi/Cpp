#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;

const int N = 2e5 + 5;
int a[N],n,q,lg[N],st[N][25];

map<int,long long> mp;
vector<int> key;
vector<long long> sum;

void solve() {
    int v;
    cin >> v;
    // 在mp的下标中找到第一个大于v的
    int cur = upper_bound(key.begin(),key.end(),v) - key.begin() - 1;
    if (cur >= 0) cout << sum[cur] << endl;
    else cout << 0 << endl;
}

int query(int l,int r) {
    int k = lg[r - l + 1];
    return st[l][k] | st[r - (1 << k) + 1][k];
}

int main() {
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    cin >> n >> q;
    int maxn = 0;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        maxn = max(maxn,a[i]);
    }
    lg[0] = -1;
    for (int k = 1;k <= n;k++) lg[k] = lg[k >> 1] + 1;
    for (int i = 1;i <= n;i++) st[i][0] = a[i];
    for (int j = 1;j <= 20;j++)
        for (int i = 1;i + (1 << j) - 1 <= n;i++)
            st[i][j] = st[i][j - 1] | st[i + (1 << (j - 1))][j - 1];
    
    for (int i = 1;i <= n;i++) {
        int cur = i;
        while (cur <= n) {
            int tmp = query(i,cur);
            // 二分
            int l = cur,r = n,ans = cur;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (query(i,mid) == tmp) l = mid + 1,ans = mid;
                else r = mid - 1;
            }
            mp[tmp] += ans - cur + 1;
            cur = ans + 1;
        }
    }
    long long tmp = 0;
    for (auto p : mp) {
        key.push_back(p.first);
        tmp += p.second;
        sum.push_back(tmp);
    }
    while (q--) solve();
    return 0;
}