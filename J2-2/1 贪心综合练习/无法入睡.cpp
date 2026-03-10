#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 105;
bool a[N];

int main(){
	int n,ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) if (!a[i] && a[i - 1] && a[i + 1]) ans++,a[i + 1] = 0;
	cout << ans << endl;
	return 0;
}