#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

const int N = 2e5 + 5;
int a[N],f[N],s[N],lg[N],st[N][30];
map<int,int> mp;

int query(int l,int r) {
    int k = lg[r - l + 1];
    return max(st[l][k],st[r - (1 << k) + 1][k]);
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        s[i] = max(s[i - 1],mp[a[i]] + 1);
        f[i] = i - s[i] + 1;
        mp[a[i]] = i;
    }
    lg[1] = 0;
    for (int i = 2;i <= n;i++) lg[i] = lg[i / 2] + 1;
    for (int i = 1;i <= n;i++) st[i][0] = f[i];
    for (int j = 1;j <= lg[n];j++)
        for (int i = 1;i + (1 << j) - 1 <= n;i++)
            st[i][j] = max(st[i][j - 1],st[i + (1 << j - 1)][j - 1]);
    while (m--) {
        int l,r;
        cin >> l >> r;
        l++,r++;
        int p = lower_bound(s + l,s + r + 1,l) - s;
        if (p > r) cout << r - l + 1 << endl;
        else cout << max(p - l,query(p,r)) << endl;
    }
    return 0;
}