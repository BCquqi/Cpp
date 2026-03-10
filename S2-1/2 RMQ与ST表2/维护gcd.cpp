#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<cmath>
using namespace std;

const int N = 1e5 + 5;
int a[N],lg[N],st[N][30];
unordered_map<int,long long> mp;

int query(int l,int r) {
	int k = lg[r - l + 1];
	return __gcd(st[l][k],st[r - (1 << k) + 1][k]);
}

int main() {
	int n,q;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	lg[1] = 0;
	for (int i = 2;i <= n;i++) lg[i] = lg[i / 2] + 1;
	for (int i = 1;i <= n;i++) st[i][0] = a[i];
	for (int j = 1;j <= lg[n];j++)
		for (int i = 1;i + (1 << j) - 1 <= n;i++)
			st[i][j] = __gcd(st[i][j - 1],st[i + (1 << j - 1)][j - 1]);
	for (int i = 1;i <= n;i++) {
		int j = i;
		while (j <= n) {
			int t = query(i,j);
			int L = j,R = n,pos = -1;
			while (L <= R) {
				int mid = L + R >> 1;
				if (query(i,mid) == t) pos = mid,L = mid + 1;
				else R = mid - 1;
			}
			mp[t] += pos - j + 1;
			j = pos + 1;
		}
	}
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << mp[x] << endl;
	}
	return 0;
}