#include<iostream>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int tree[N],n,a[N],h[N],dp[N];

// 带权最长上升子序列

int lowbit(int x) {return x & -x;}
void add(int id,int val) {while (id <= n) tree[id] = max(tree[id],val), id += lowbit(id);}
int query(int id) {
    int ret = 0;
    while (id) ret = max(ret,tree[id]), id -= lowbit(id);
    return ret;
}

signed main() {
	int ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> h[i];
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) {
		dp[i] = query(h[i] - 1) + a[i];
		add(h[i],dp[i]);
		ans = max(ans,dp[i]);
	}
	cout << ans << endl;
	return 0;
} 
