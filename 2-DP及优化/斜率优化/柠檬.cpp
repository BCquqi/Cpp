#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
#include<vector>
#define int long long
using namespace std;

const int N = 1e5 + 5,M = 1e4 + 5;
int s[N],a[N],dp[N],box[M],n;
vector<int> st[M];

inline int calc(int x,int y) 
{return 1ll * dp[x - 1] + s[x] * y * y;}

int bound(int x,int y) {
    int l = 1,r = n,ret = n + 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (calc(x,mid - a[x] + 1) >= calc(y,mid - a[y] + 1)) r = mid - 1,ret = mid;
        else l = mid + 1;
    }
    return ret;
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> s[i];
        a[i] = ++box[s[i]];
        while (st[s[i]].size() >= 2 && bound(st[s[i]][st[s[i]].size() - 2],st[s[i]][st[s[i]].size() - 1]) <= bound(st[s[i]][st[s[i]].size() - 1],i))
            st[s[i]].pop_back();
        st[s[i]].push_back(i);
        while (st[s[i]].size() >= 2 && bound(st[s[i]][st[s[i]].size() - 2],st[s[i]][st[s[i]].size() - 1]) <= a[i])
            st[s[i]].pop_back();
        dp[i] = calc(st[s[i]][st[s[i]].size() - 1],a[i] - a[st[s[i]][st[s[i]].size() - 1]] + 1);
    }
    cout << dp[n] << endl;
    return 0;
}