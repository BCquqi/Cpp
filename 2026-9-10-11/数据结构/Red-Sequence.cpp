#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e6 + 5;
int dp[N],n,mx;
int A[N],C[N];
vector<int> vec[N * 2];
vector<int> bit[N * 2];

void update(int a,int c,int w) {
    for (int x = a;x <= mx;x += x & -x) {
        int y = lower_bound(vec[x].begin(),vec[x].end(),c) - vec[x].begin() + 1;
        for (int z = y;z < bit[x].size();z += z & -z)
            bit[x][z] = max(bit[x][z],w);
    }
    return ;
}

int query(int a,int c) {
    int res = -1e9;
    for (int x = a;x > 0;x -= x & -x) {
        int y = upper_bound(vec[x].begin(),vec[x].end(),c) - vec[x].begin();
        for (int z = y;z > 0;z -= z & -z)
            res = max(res,bit[x][z]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    mx = 2 * n + 2;
    int a = 0,c = 0;
    A[0] = 0, C[0] = 0;
    for (int i = 1;i <= n;i++) {
        int r,y,b;
        cin >> r >> y >> b;
        a += r - y,c += r - b;
        A[i] = a, C[i] = c;
    }
    for (int i = 0;i <= n;i++)
        for (int x = A[i] + n + 1;x <= mx;x += x & -x)
            vec[x].push_back(C[i]);
    for (int x = 1;x <= mx;x++) {
        if (vec[x].empty()) continue;
        sort(vec[x].begin(),vec[x].end());
        vec[x].erase(unique(vec[x].begin(),vec[x].end()),vec[x].end());
        bit[x].assign(vec[x].size() + 1,-1e9);
    }
    update(A[0] + n + 1,C[0],0);
    for (int i = 1;i <= n;i++) {
        int maxw = query(A[i] + n + 1,C[i]);
        dp[i] = dp[i - 1];
        if (maxw != -1e9) dp[i] = max(dp[i],i + maxw);
        update(A[i] + n + 1,C[i],dp[i] - i);
    }
    cout << dp[n] << endl;
    return 0;
}