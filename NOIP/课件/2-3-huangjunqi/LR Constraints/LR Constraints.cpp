#include<iostream>
#include<algorithm>
using namespace std;

const int mod = 998244353,N = 1005;
int K[N],cntK[N];

int main() {
	int n,k;
	cin >> n >> k;
	int cntn = n; // cntn表示还剩多少个可以自由分配的空位
	for (int i = 1;i <= k;i++) {
		int c,k;
		cin >> c >> k;
		K[i] = max(K[i],k),cntn--;
	}
	return 0;
}
