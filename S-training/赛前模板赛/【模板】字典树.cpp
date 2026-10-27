#include<iostream>
#include<cstring>
using namespace std;

const int N = 3e6 + 5,M = 30;
int ch[N][M],sum[N],cnt[N],id = 1;

void insert(string s) {
    int x = 1;
    for (auto c : s) {
        int i = c - 'a';
        if (!ch[x][i]) {
            ch[x][i] = ++id;
            memset(ch[id],0,sizeof ch[id]);
            sum[id] = 0,cnt[id] = 0;
        }
        x = ch[x][i];
        sum[x]++;
    }
    cnt[x]++;
}

int query(string s) {
    int x = 1;
    for (auto c : s) {
        int i = c - 'a';
        if (!ch[x][i]) return 0;
        x = ch[x][i];
    }
    return sum[x];
}

void solve() {
    id = 1;
    memset(ch[1],0,sizeof ch[1]);
    sum[1] = 0,cnt[1] = 0;
    int n,q;
    cin >> n >> q;
    while (n--) {
        string s;
        cin >> s;
        insert(s);
    }
    while (q--) {
        string s;
        cin >> s;
        cout << query(s) << endl;
    }
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}