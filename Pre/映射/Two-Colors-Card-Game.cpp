#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

map<string,int> mp;

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		string s;
		cin >> s;
		mp[s]++;
	}
	int m;
	cin >> m;
	for (int i = 1;i <= m;i++)
	{
		string s;
		cin >> s;
		mp[s]--;
	}
	int ans = 0;
	for (auto kv : mp)
	{
		ans = max(ans,kv.second);
	}
	cout << ans << endl;
    return 0;
}
