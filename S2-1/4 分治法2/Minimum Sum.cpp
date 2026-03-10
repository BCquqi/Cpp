#include<iostream>
using namespace std;

const int N = 2e5 + 5;
int a[N],lg[N],st[N][30];

int query(int l,int r) {
	int k = lg[r - l + 1];
	int ret = (a[st[l][k]] < a[st[r - (1 << k) + 1][k]]) ? st[l][k] : st[r - (1 << k) + 1][k];
	return ret;
}

long long merge_sort(int L,int R) {
	if (L > R) return 0;
	int mid = query(L,R);
	long long cntL = merge_sort(L,mid - 1),cntR = merge_sort(mid + 1,R);
	long long cnt = 1ll * a[mid] * (mid - L + 1) * (R - mid + 1);
	return cntL + cntR + cnt;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	lg[1] = 0;
	for (int i = 2;i <= n;i++) lg[i] = lg[i / 2] + 1;
	for (int i = 1;i <= n;i++) st[i][0] = i;
	for (int j = 1;j <= lg[n];j++)
		for (int i = 1;i + (1 << j) - 1 <= n;i++)
			st[i][j] = (a[st[i][j - 1]] < a[st[i + (1 << j - 1)][j - 1]]) ? st[i][j - 1] : st[i + (1 << j - 1)][j - 1];
	cout << merge_sort(1,n) << endl;
	return 0;
}