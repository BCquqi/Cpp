#include<iostream>
#include<cstdio>
#include<algorithm>
#include<list>
using namespace std;

list<char> ls;

int main() {
	string s;
	cin >> s;
	auto pos = ls.begin();
	for (int i = 0;i < s.size();i++) {
		if (s[i] == '[') pos = ls.begin();
		else if (s[i] == ']') pos = ls.end();
		else if (s[i] == '#' && pos != ls.begin()) pos = ls.erase(--pos);
		else if (s[i] != '#') ls.insert(pos,s[i]);
	}
	for (auto t : ls) cout << t;
	cout << endl;
    return 0;
}