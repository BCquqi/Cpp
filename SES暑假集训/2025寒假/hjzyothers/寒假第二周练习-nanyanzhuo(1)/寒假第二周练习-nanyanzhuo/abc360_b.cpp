#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;
string s,t;
int ans=0;
int main(){
	cin >> s >> t;
	for(int w=1;w<s.size();w++){
		for(int c=1;c<=w;c++){
			int to=0;
			string tmp="";
			int n=s.size();
			while(to<s.size()&&min(w,n-to)>=c){
				tmp+=s[to+c-1];
				to+=w;
			}
			if(t==tmp){
				ans=1;
				break;
			}
		}
	}
	if(ans) cout << "Yes";
	else cout << "No";
	return 0;
}
