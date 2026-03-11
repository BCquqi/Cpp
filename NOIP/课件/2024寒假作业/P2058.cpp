#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct B{
	int t,k;
};

int v[100005];

int main(){
	queue<B> q;
	int n,cnt = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int t,k;
		cin >> t >> k;
		for(int i = 1;i <= k;i++)
		{
			int x;
			cin >> x;
			q.push({t,x});
			v[x]++;
			if(v[x] == 1)
			{
				cnt++;
			}
			while(t - q.front().t >= 86400)
			{
				int tmp = q.front().k;
				q.pop();
				v[tmp]--;
				if (v[tmp] == 0)
				{
					cnt--;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
