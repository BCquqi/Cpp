#include<cstdio>
#include <iostream>
#include <cstdlib>
#define ll long long
using namespace std;
const ll N=2e5+10,mod=998244353;
ll a[N],sum[N];
ll f(ll x) {
  ll cnt=0;
  while(x){
  	cnt++;
  	x/=10;
  } 
  return cnt;
}
ll pow10(ll x) {
  ll ans=1;
  while(x--) ans=ans*10%mod;
  return ans;
}
int main() {
  ll n,ans=0;
   cin >>n;
  for(ll i=1;i<=n;i++){
  	cin >>a[i];
	sum[i]=(sum[i-1]+a[i])%mod;
  } 
  for(ll i=2;i<=n;i++){
  	 ans=(ans+(sum[i-1]*pow10(f(a[i]))%mod+(i-1)*a[i]%mod)%mod)%mod;
  }
  
  cout << ans;
  return 0;
}
