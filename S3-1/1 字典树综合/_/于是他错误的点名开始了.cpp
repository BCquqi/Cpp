#include<iostream>
#include<map>
using namespace std;

const int N = 1e6 + 5,M = 30;
int ch[N][M],sum[N],cnt[N],id = 1;

map<string,bool> mp;

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

bool query(string s) {
    int x = 1;
    for (auto c : s) {
        int i = c - 'a';
        if (!ch[x][i]) return 0;
        x = ch[x][i];
    }
    return cnt[x];
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        insert(s);
    }
    int m;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;
        if (mp[s]) {
            cout << "REPEAT" << endl;
            continue;
        }
        if (query(s)) {
            cout << "OK" << endl;
            mp[s] = true;
            continue;
        }
        cout << "WRONG" << endl;
    }
    return 0;
}