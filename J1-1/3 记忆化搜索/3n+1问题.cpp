// 特别声明：本题请务必关闭输入输出流，否则可能超时！
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e7 + 10;

long long ans[N];

long long F(long long x)
{
	if (x > 1e7)
	{
		if (x % 2 == 0) return F(x / 2) + 1;
		else return F(x * 3 + 1) + 1;
	}
	if (ans[x] != -1) return ans[x];
	if (x == 1) return ans[x] = 1;
	if (x % 2 == 0) return ans[x] = F(x / 2) + 1;
	else return ans[x] = F(x * 3 + 1) + 1;
}

int main(){
	int q;
	scanf("%d",&q);
	int x;
	memset(ans,-1,sizeof ans);
	while (q--)
	{
		scanf("%d",&x);
		printf("%d\n",F(x));
	}
	return 0;
}