#include<iostream>
using namespace std;

const int N = 40;
int a[N],m,n;
long long ans = 0;

void dfs(int step,long long sum) {
	if (step > n) {
		ans = max(ans,sum % m);
		return ;
	}
	dfs(step + 1,(sum + a[step]) % m);
	dfs(step + 1,sum);
}

int main() {
	cin >> m >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	dfs(1,0);
	cout << ans << endl;
	return 0;
}