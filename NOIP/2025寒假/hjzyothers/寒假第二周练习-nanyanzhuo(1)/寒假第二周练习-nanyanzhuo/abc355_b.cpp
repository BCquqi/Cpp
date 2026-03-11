#include <bits/stdc++.h>
using namespace std;
int ans=0;
struct f{
	char from;
	int val;
};
f c[1000007];
int cmp(f a,f b){
	return a.val < b.val;
}
int main(){
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> c[i].val;
		c[i].from='a';
	}	
	for(int i=n;i<=m+n;i++){
		cin >> c[i].val;
		c[i].from='b';
	}	
	sort(c+1,c+1+n+m,cmp);
	for(int i=1;i<=n+m;i++){
		if(c[i].from==c[i+1].from&&c[i].from=='a'){
			ans=1;
			break;
		}
	}
	if(ans) cout << "Yes";
	else cout <<"No";
	return 0;
}
