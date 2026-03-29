#include<iostream>
#include<map>
using namespace std;

map<string,string> f;

string find(string x) {return x == f[x] ? x : f[x] = find(f[x]);}

void Union(string x,string y) {
    string fx = find(x),fy = find(y);
    if (fx != fy) f[fx] = fy;
}

int main() {
	string s,fa;
	char c;
	while (cin >> c) {
		if (c == '$') break;
		cin >> s;
		if (f.count(s) == 0) f[s] = s;
		if (c == '#') fa = s;
		else if (c == '+') Union(s,fa);
		else cout << s << ' ' << find(s) << endl;
	}
	return 0;
}