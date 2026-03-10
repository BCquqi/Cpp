#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main(){
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	int x = a[n / 2 + 1];
	long long ans = 0;
	for (int i = 1;i <= n;i++) ans += abs(x - a[i]);
	cout << ans << endl;
	return 0;
}