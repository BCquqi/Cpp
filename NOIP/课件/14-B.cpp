#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[20005];
ll n,l,mx,f,s,x,y;
void dfs(int a,int b){
    if(a+mx>=l){
        f=1;
        return;
    }
    for(int i=a;i<=a+mx;i++)
        if(b>=p[i])
            dfs(i,b-p[i]);
        return;
}
int main(){
    while(cin>>n>>l>>mx>>s){
        memset(p,0x3f,sizeof(p));
        f=0;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            p[x]=min(p[x],y);
        }
        dfs(0,s);
        if(f)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
              
    }
    return 0;
}
