#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long LL;

const int N = 110;

queue<LL> q[N];
int p[N];

int main(){
	int k,n;
	cin >> k >> n;
	for (int i = 1;i <= k;i++)
	{
		cin >> p[i];
		q[i].push(p[i]);
	}
	LL minn = 1e18;
	for (int i = 1;i <= n;i++)
	{
		minn = q[1].front();
		for (int j = 2;j <= k;j++)
		{
			minn = min(minn,q[j].front());
		}
		for (int j = 1;j <= k;j++)
		{
			q[j].push(minn * p[j]);
			if (minn == q[j].front()) q[j].pop();
		}
	}
	cout << minn;
	return 0;
}
