#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int b,d,p;
long long ans[1000005];

long long F(int x)
{
	if (x > b) return 2e9;
	if (ans[x] != -1) return ans[x];
	if (x == b) return ans[x] = 0;
	return ans[x] = min(F(x + d),F(p * x + 1)) + 1;
}

int main(){
	memset(ans,-1,sizeof ans);
	cin >> b >> d >> p;
	if (F(1) < 2e9) cout << F(1) << endl;
	else cout << -1 << endl;
	return 0;
}