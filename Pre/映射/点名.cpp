#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

map<string,bool> mp;

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		string s;
		cin >> s;
		mp[s] = 0;
	}
	int m;
	cin >> m;
	for (int i = 1;i <= m;i++)
	{
		string s;
		cin >> s;
		if (mp.count(s) == 0)
		{
			cout << "WRONG" << endl;
			continue;
		}
		if (!mp[s])
		{
			cout << "OK" << endl;
			mp[s] = true;
		}
		else 
		{
			cout << "REPEAT" << endl;
		}
	}
    return 0;
}
