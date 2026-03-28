#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

map<long long,int> mp;
long long a[100005],b[100005];

int main() {
	long long n,k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> b[i];
		mp[a[i]] += b[i];
	}
	for (auto kv : mp)
	{
		k -= kv.second;
		if (k <= 0)
		{
			cout << kv.first << endl;
			break;
		}
	}
    return 0;
}
