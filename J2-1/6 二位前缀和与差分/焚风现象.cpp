#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e5 + 5;
int a[N],d[N],n,q,s,t;

long long cal(int x)
{
	if (x > 0) return -1ll * x * s;
	else return -1ll * x * t;
}

int main(){
	cin >> n >> q >> s >> t;
	for (int i = 0;i <= n;i++) {cin >> a[i]; d[i] = a[i] - a[i - 1];}
	long long T = 0;
		for (int i = 1;i <= n;i++)
		{
			T += cal(d[i]);
		}
	while (q--)
	{
		int l,r,x;
		cin >> l >> r >> x;
		T -= cal(d[l]),d[l] += x,T += cal(d[l]);
		if (r + 1 <= n) T -= cal(d[r + 1]),d[r + 1] -= x,T += cal(d[r + 1]);
		cout << T << endl;
	}
	return 0;
}