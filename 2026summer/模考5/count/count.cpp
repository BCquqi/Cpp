#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;

const int N = 2e5 + 5;
int a[N],n,q,lg[N],st[N][25];

map<int,int> mp;

void solve() {
    int v;
    cin >> v;
    // 在mp的下标中找到第一个大于v的
    
}

int query(int l,int r) {
    int k = lg[r - l + 1];
    return st[l][k] | st[r - (1 << k) + 1][k];
}

int main() {
    cin >> n >> q;
    int maxn = 0;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        maxn = max(maxn,a[i]);
    }
    lg[0] = -1;
    for (int k = 1;k <= N;k++) lg[k] = lg[k >> 1] + 1;
    for (int i = 1;i <= n;i++) st[i][0] = a[i];
    for (int j = 1;j <= 20;j++)
        for (int i = 1;i + (1 << j) - 1 <= n;i++)
            st[i][j] = st[i][j - 1] | st[i + (1 << (j - 1))][j - 1];
    
    for (int i = 1;i <= n;i++) {
        int cur = i;
        while (cur <= n) {
            int tmp = query(l,cur);
            // 二分
            int l = cur,r = n,ans = cur;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (query(l,mid) == tmp) l = mid + 1,ans = mid;
                else r = mid - 1;
            }
            mp[tmp] += ans - cur + 1;
            cur = ans;
        }
    }
    while (q--) solve();
    return 0;
}