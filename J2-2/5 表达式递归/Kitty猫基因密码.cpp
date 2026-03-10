#include<iostream>
using namespace std;

int check(string s) {
	bool flaga = true,flagb = true;
	for (auto c : s) flaga &= (c == '0'),flagb &= (c == '1');
	return (flaga ? 1 : (flagb ? 2 : 0));
}

string dfs(string s) {
	int flag = check(s);
	if (flag == 1) return "A";
	else if (flag == 2) return "B";
	return "C" + dfs(s.substr(0,s.size() / 2)) + dfs(s.substr(s.size() / 2));
}

int main() {
	string s;
	cin >> s;
	cout << dfs(s) << endl;
	return 0;
}