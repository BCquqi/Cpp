#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
const int MAXN=100000+10;
using namespace std;
int n,l,len[MAXN];
int readint()
{
	int x;
	scanf("%d",&x);
	return x;
}
void solve(){
	n=readint(),l=readint();
	
	_for(i,0,n)len[i]=readint();
		 
	sort(len,len+n,greater<int>());
	 
	int ans=0,left=0,right=n-1;
	
	while(left<=right){
		ans++;left++;
		if(left!=right && (len[left]+len[right]<=1))right--;
	}
	printf("%d\n",ans);
}
int main(){
	freopen("UVa1149.in","r",stdin);
	//freopen("UVa1149.out","w",stdout);
	int k=readint(),first=1;
	while(k--){
		if(first)first=0;
		else puts("");
		solve();
	}
}
