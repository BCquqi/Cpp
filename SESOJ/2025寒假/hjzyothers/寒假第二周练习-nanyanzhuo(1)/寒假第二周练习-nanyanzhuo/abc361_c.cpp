#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
int a[10000007];
int ans=1e9+7;
int main(){
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=k+1;i++){
		ans=min(ans,a[i+n-k-1]-a[i]);
	}
	cout << ans;
	return 0;
}
