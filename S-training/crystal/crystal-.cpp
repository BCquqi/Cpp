#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=5e5+9;
long long n,m,a[maxn],sum[maxn],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)sum[i]=a[i]+sum[i-1];
	sort(a+1,a+n+1);
	for(int l=1,r=1;r<=n;r++){
		while(l<=r){
			const long long cnt=(r-l+1LL)*a[r]-(sum[r]-sum[l-1]);
			if(cnt>m)l++;
			else break;
		}
		ans=max(ans,r-l+1LL);
	}
	cout<<ans;
    return 0;
}
