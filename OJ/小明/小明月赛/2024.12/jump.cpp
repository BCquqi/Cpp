#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

bool flag1[1005],flag2[1005];

int n,d;

int change1(int x)
{
	x = (x + d) % n;
	if (x == 0) x = n;
	return x;
}

int change2(int x)
{
	x = (x - d + n) % n;
	if (x == 0) x = n;
	return x;
}

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin >> n >> d;
	int id = 1,ans1 = 0,ans2 = 0;
	while (!flag1[change1(id)])
	{
		id = change1(id);
		flag1[id] = true;
		ans1++;
	}
	id = 1;
	while (!flag2[change2(id)])
	{
		id = change2(id);
		flag2[id] = true;
		ans2++;
	}
	cout << max(ans1,ans2) - 1 << endl;
	return 0;
}
