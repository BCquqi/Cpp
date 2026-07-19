#include<iostream>
using namespace std;

const int N = 5e5 + 5;
int cnt[N],sum[N],ch[N][2],id = 1;

void insert(string s) {
	int x = 1;
	for (auto c : s) {
		int i = c - '0';
		if (!ch[x][i]) ch[x][i] = ++id;
		x = ch[x][i];
		sum[x]++;
	}
	cnt[x]++;
}

int query(string s) {
	int x = 1,ret = 0;
	for (auto c : s) {
		int i = c - '0';
		if (!ch[x][i]) return ret;
		x = ch[x][i];
		ret += cnt[x];
	}
	return ret + sum[x] - cnt[x];
}

int main() {
	int n,m;
	cin >> n >> m;
	while (n--) {
		int x;
		string s;
		cin >> x;
		while (x--) {
			char c;
			cin >> c;
			s += c;
		}
		insert(s);
	}
	while (m--) {
		int x;
		string s;
		cin >> x;
		while (x--) {
			char c;
			cin >> c;
			s += c;
		}
		cout << query(s) << endl;
	}
	return 0;
}