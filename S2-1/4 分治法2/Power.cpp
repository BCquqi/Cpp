#include<iostream>
using namespace std;

const int N = 5e5 + 5;
int v[N],lg[N],st[N][30];
long long e,r,n;

int query(int L,int R) {
	int k = lg[R - L + 1];
	int ret = (v[st[L][k]] > v[st[R - (1 << k) + 1][k]]) ? st[L][k] : st[R - (1 << k) + 1][k];
	return ret;
}

long long merge(int L,int R,long long start,long long end) {
	if (L > R) return 0;
	int mid = query(L,R);
	long long emax = min(e,start + (mid - L) * r),emin = max(0ll,end - (R - mid + 1) * r);
	long long ans = (emax - emin) * v[mid] + merge(L,mid - 1,start,emax) + merge(mid + 1,R,min(emin + r,e),end);
	return ans;
}

void solve() {
	cin >> e >> r >> n;
	for (int i = 1;i <= n;i++) cin >> v[i];
	for (int i = 1;i <= n;i++) st[i][0] = i;
	for (int j = 1;j <= lg[n];j++)
		for (int i = 1;i + (1 << j) - 1 <= n;i++)
			st[i][j] = (v[st[i][j - 1]] > v[st[i + (1 << j - 1)][j - 1]]) ? st[i][j - 1] : st[i + (1 << j - 1)][j - 1];
	cout << merge(1,n,e,0) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	lg[1] = 0;
	for (int i = 2;i <= 500000;i++) lg[i] = lg[i / 2] + 1;
	while (T--) solve();
	return 0;
}