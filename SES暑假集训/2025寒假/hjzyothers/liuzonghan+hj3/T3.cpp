#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int a,b,c;
int quick_pow(int a,int x,int mod) 
{
	int res=1;
	for (;x;x>>=1,a=a*a%mod)
	{
		if(x&1)
		{
			res=res*a%mod;
		}
	}
	return res;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c;
	a%=10;
	b%=4;
	cout<<quick_pow(a,4+quick_pow(b,c,4),10)<<endl;
	return 0;
}
