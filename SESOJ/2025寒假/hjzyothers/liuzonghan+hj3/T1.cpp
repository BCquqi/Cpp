#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,ans=-1e9,x,y;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    x=n,y=m;
    ans=max(ans,(x%100+900-y));
    ans=max(ans,((x/100)*100+x%10+90)-y);
    ans=max(ans,x+9-x%10-y);
    ans=max(ans,x-(y%100+100));
    ans=max(ans,x-((y/100)*100+y%10));
    ans=max(ans,x-(y-y%10));
    cout<<ans<<endl;
    return 0;
}

