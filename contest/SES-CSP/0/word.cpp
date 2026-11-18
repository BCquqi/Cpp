#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 1005;

bool check(string s) {
	int len = s.size();
	s = ' ' + s;
	if (!('A' <= s[1] && s[1] <= 'Z')) return false;
	if (len == 1) return true;
	for (int i = 2;i < len;i++)
		if (!('a' <= s[i] && s[i] <= 'z')) return false;
	if (!(('a' <= s[len] && s[len] <= 'z') || s[len] == '.' || s[len] == '?' || s[len] == '!'))
		return false;
	return true;
}

int main() {
	freopen("word.in","r",stdin);
	freopen("word.out","w",stdout);
	int n,ans = 0;
	cin >> n;
	char c;
	string s,word;
	getchar();
	getline(cin,s);
	for (auto c : s) {
		if (c == ' ') {
			if (check(word)) ans++;
			word = "";
		} else if (c == '.' || c == '?' || c == '!') {
			if (check(word)) ans++;
			word = "";
			cout << ans << endl;
			ans = 0;
		} else word += c;
	}
	return 0;
}