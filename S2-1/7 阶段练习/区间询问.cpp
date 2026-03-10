#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int a[N],lg[N],st[N][30],stid[N][30];

int query(int l,int r) {
	int k = lg[r - l + 1];
	return max(st[l][k],st[r - (1 << k) + 1][k]);
}

int queryid(int l,int r) { // 查最大值的下标
	int k = lg[r - l + 1];
	return (st[l][k] > st[r - (1 << k) + 1][k]) ? stid[l][k] : stid[r - (1 << k) + 1][k];
}

// int scquery(int l,int r,int maxn,int maxid) { // 求次大的值
// 	int newmaxn = max(query(l,maxid - 1),query(maxid + 1,r)); // 两边的最大
// 	int lmaxid = queryid(l,maxid - 1),
// 	if (newmaxn == maxn)
// 		return scquery(l,maxid - 1,maxn,)
// 	return ;
// }

// 以i开头，长度为2^j范围里面的最大
int main() {
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	lg[0] = 1;
	for (int i = 2;i <= n;i++) lg[i] = lg[i / 2] + 1;
	for (int i = 1;i <= n;i++) st[i][0] = a[i],stid[i][0] = i;
	for (int j = 1;j <= lg[n];j++)
		for (int i = 1;i + (1 << j) - 1 <= n;i++) {
			st[i][j] = max(st[i][j - 1],st[i + (1 << j - 1)][j - 1]);
			
			if (st[i][j] == st[i][j - 1]) stid[i][j] = stid[i][j - 1];
			else stid[i][j] = stid[i + (1 << j - 1)][j - 1];
		}
	for (int i = 1;i <= m;i++) {
		int l,r,maxn,maxid,scmaxn;
		cin >> l >> r;
		maxn = query(l,r);
		maxid = queryid(l,r);
		if (maxid == 1) scmaxn = query(maxid + 1,r);
		else if (maxid == n) scmaxn =
		scmaxn = max(query(l,maxid - 1),query(maxid + 1,r));
		cout << maxn << ' ' << maxid << endl;
	}
	return 0;
}