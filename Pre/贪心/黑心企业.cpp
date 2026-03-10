#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int p[300005],w[300005];

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	for (int i = 1;i <= n;i++) cin >> p[i];
	for (int i = 1;i <= m;i++) cin >> w[i];
	sort(p + 1,p + n + 1);
	sort(w + 1,w + m + 1);
	long long ans = 0;
	for (int i = 1,j = 1;i <= n && j <= m;i++,j++)
	{
		while(p[i] < w[j]) i++;
		ans += 1ll * k * p[i];
	}
	cout << ans << endl;
	return 0;
}
