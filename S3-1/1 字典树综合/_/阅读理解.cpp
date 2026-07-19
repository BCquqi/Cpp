#include<iostream>
#include<map>
#include<bitset>
using namespace std;

const int N = 5e5 + 5,M = 30;
int ch[N][M],sum[N],cnt[N],id = 1,n;
bitset<1005> a[N];

void insert(string s,int m) {
    int x = 1;
    for (auto c : s) {
        int i = c - 'a';
        if (!ch[x][i]) ch[x][i] = ++id;
        x = ch[x][i];
        sum[x]++;
    }
    cnt[x]++;
    a[x][m] = true;
}

void query(string s) {
    int x = 1;
    for (auto c : s) {
        int i = c - 'a';
        if (!ch[x][i]) {
            cout << endl;
            return ;
        }
        x = ch[x][i];
    }
    for (int i = 1;i <= n;i++)
        if (a[x][i]) cout << i << ' ';
    cout << endl;
    return ;
}

int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int l;
        cin >> l;
        for (int j = 1;j <= l;j++) {
            string s;
            cin >> s;
            insert(s,i);
        }
    }
    int m;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;
        query(s);
    }
    return 0;
}