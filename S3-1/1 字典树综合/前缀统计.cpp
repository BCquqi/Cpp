#include<iostream>
using namespace std;

const int N = 1e6 + 5,M = 30;
int ch[N][M],cnt[N],sum[N],id = 1;

void insert(string s) {
    int x = 1;
    for (auto c : s) {
        int i = c - 'a';
        if (!ch[x][i]) ch[x][i] = ++id;
        x = ch[x][i];
        sum[x]++;
    }
    cnt[x]++;
}

int query(string s) {
    int x = 1,ret = 0;
    for (auto c : s) {
        int i = c - 'a';
        if (!ch[x][i]) return ret;
        x = ch[x][i];
        ret += cnt[x];
    }
    return ret;
}

int main() {
    int n,m;
    cin >> n >> m;
    while (n--) {
        string s;
        cin >> s;
        insert(s);
    }
    while (m--) {
        string t;
        cin >> t;
        cout << query(t) << endl;
    }
    return 0;
}