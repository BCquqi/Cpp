#include<bits/stdc++.h>
using namespace std;
#define MAXN 20010
int n,a[MAXN],b[MAXN],f[MAXN*2],dtop,ctop,d[MAXN*2];
long long c[MAXN*2];
long long ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		d[++dtop]=a[i];
		d[++dtop]=b[i];
	}
	sort(d+1,d+dtop+1);
	for(int i=1;i<=dtop;i++)
	  if(d[i]!=d[i-1] || i==1)c[++ctop]=d[i];
	for(int i=1;i<=n;i++)
	{
		int x=lower_bound(c+1,c+ctop+1,a[i])-c;
		int y=lower_bound(c+1,c+ctop+1,b[i])-c;
		for(int j=x;j<y;j++)
		   f[i]=1;
	 } 
	for(int i=1;i<ctop;i++)
	  if(f[i])ans+=c[i+1]-c[i];
	printf("%lld",ans);
	return 0;  
} 
