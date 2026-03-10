#include<iostream>
#include<algorithm>
using namespace std;

const int N = 45,M = (1 << 20) + 5;
int curL = 0,curR = 0,n;
long long m,ans = 0,L[M],R[M],a[N];

void dfsL(int step,long long sum) {
	if (sum > m) return ;
	if (step > n / 2) {
		L[++curL] = sum;
		return ;
	}
	dfsL(step + 1,sum + a[step]);
	dfsL(step + 1,sum);
}

void dfsR(int step,long long sum) {
	if (sum > m) return ;
	if (step > n) {
		R[++curR] = sum;
		return ;
	}
	dfsR(step + 1,sum + a[step]);
	dfsR(step + 1,sum);
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	dfsL(1,0);
	dfsR(n / 2 + 1,0);
	sort(R + 1,R + curR + 1);
	for (int i = 1;i <= curL;i++)
		ans += (upper_bound(R + 1,R + curR + 1,m - L[i]) - R) - 1;
	cout << ans << endl;
	return 0;
}