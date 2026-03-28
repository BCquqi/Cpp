#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define LL long long
LL n,k;
LL solve(LL sum) 
{
    LL tot = sum-1;
    LL sub = max(0LL,sum-n-1);
    return max(0LL,tot-2*sub);
}
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>k;
    LL ans=0;
    for(LL i=k;i<=2*n;i++) 
	{
        ans += (solve(i)*solve(i-k));
    }
    cout<<ans<<endl;
    return 0;
}
