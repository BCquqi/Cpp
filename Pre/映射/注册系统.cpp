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
		if (mp[s] == 0)
		{
			cout << "OK" << endl;
			mp[s]++;
			continue;
		}
		cout << s << mp[s] << endl;
		mp[s]++;
	}
    return 0;
}
