#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,q,u,v,t,len[100009];
queue<ll> a,b,c;
int main(){
	scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&q,&u,&v,&t);
	for(ll i=1;i<=n;i++) scanf("%lld",&len[i]);
	sort(len+1,len+n+1);
	for(ll i=n;i>=1;i--) a.push(len[i]);
	for(ll i=1;i<=m;i++){
		ll now=-1e17,k=0;
		if(!a.empty()&&a.front()>now) now=a.front(),k=1;
		if(!b.empty()&&b.front()>now) now=b.front(),k=2;
		if(!c.empty()&&c.front()>now) now=c.front(),k=3;
		if(k==1) a.pop();
		if(k==2) b.pop();
		if(k==3) c.pop();
		now+=(i-1)*q;
		if(i%t==0) printf("%lld ",now);
		ll x1=(now*u/v)-q*i;
		ll x2=(now-now*u/v)-q*i;
		b.push(x1);
		c.push(x2);
	}
	printf("\n");
	for(ll i=1;i<=n+m;i++){
		ll now=-1e17,k=0;
		if(!a.empty()&&a.front()>now) now=a.front(),k=1;
		if(!b.empty()&&b.front()>now) now=b.front(),k=2;
		if(!c.empty()&&c.front()>now) now=c.front(),k=3;
		if(k==1) a.pop();
		if(k==2) b.pop();
		if(k==3) c.pop();
		now+=m*q;
		if(i%t==0) printf("%lld ",now);
	}
    return 0;
}
