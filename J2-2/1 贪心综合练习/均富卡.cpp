#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
int a[N];
long long s[N];

void solve()
{
	memset(s,0,sizeof s);
	int n,x;
	cin >> n >> x;
	
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1,greater<int> () );
	for (int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
	for (int i = n;i >= 1;i--)
		if (s[i] / i >= x) {cout << i << endl; return ;}
	cout << 0 << endl;
}

int main(){
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}