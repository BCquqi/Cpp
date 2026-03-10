#include<iostream>
#include<algorithm>
using namespace std;

const int N = 10,M = 150 * 150 * 150 + 5;
int k[N],p[N],L[M],R[M],n,m,curL = 0,curR = 0,ans = 0;

int qpow(int a,int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

void dfsL(int step,int sum) {
	if (step > n / 2) {
		L[++curL] = sum;
		return ;
	}
	for (int i = 1;i <= m;i++)
		dfsL(step + 1,sum + k[step] * qpow(i,p[step]));
}

void dfsR(int step,int sum) {
	if (step > n) {
		R[++curR] = sum;
		return ;
	}
	for (int i = 1;i <= m;i++)
		dfsR(step + 1,sum + k[step] * qpow(i,p[step]));
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> k[i] >> p[i];
	dfsL(1,0); dfsR(n / 2 + 1,0);
	sort(L + 1,L + curL + 1);
	sort(R + 1,R + curR + 1);
	for (int i = 1;i <= curL;i++) {
		int pos1 = upper_bound(R + 1,R + curR + 1,0 - L[i]) - R;
		int pos2 = lower_bound(R + 1,R + curR + 1,0 - L[i]) - R;
		int pos3 = upper_bound(L + 1,L + curL + 1,L[i]) - L;
		ans += (pos3 - i) * (pos1 - pos2);
		i = pos3 - 1;
	}
	cout << ans << endl;
	return 0;
}