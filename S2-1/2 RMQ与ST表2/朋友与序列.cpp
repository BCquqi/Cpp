#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e5 + 5;
int a[N],b[N],lg[N],stmax[N][30],stmin[N][30];

int querya(int l,int r) {
	int k = lg[r - l + 1];
	return max(stmax[l][k],stmax[r - (1 << k) + 1][k]);
}

int queryb(int l,int r) {
	int k = lg[r - l + 1];
	return min(stmin[l][k],stmin[r - (1 << k) + 1][k]);
}

int main() {
	int n;
	long long ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) cin >> b[i];
	lg[1] = 0;
	for (int i = 2;i <= n;i++) lg[i] = lg[i / 2] + 1;
	for (int i = 1;i <= n;i++) stmax[i][0] = a[i], stmin[i][0] = b[i];
	for (int j = 1;j <= lg[n];j++)
		for (int i = 1;i + (1 << j) - 1 <= n;i++)
			stmax[i][j] = max(stmax[i][j - 1],stmax[i + (1 << j - 1)][j - 1]),
			stmin[i][j] = min(stmin[i][j - 1],stmin[i + (1 << j - 1)][j - 1]);
	for (int i = 1;i <= n;i++) {
		int L = i,R = n,pos1 = n + 1,pos2 = n + 1;
		while (L <= R) {
			int mid = L + R >> 1;
			if (querya(i,mid) - queryb(i,mid) > 0)
				R = mid - 1,pos1 = mid;
			else L = mid + 1;
		}
		L = i,R = n;
		while (L <= R) {
			int mid = L + R >> 1;
			if (querya(i,mid) - queryb(i,mid) >= 0)
				R = mid - 1,pos2 = mid;
			else L = mid + 1;
		}
		ans += pos1 - pos2;
	}
	cout << ans << endl;
	return 0;
}