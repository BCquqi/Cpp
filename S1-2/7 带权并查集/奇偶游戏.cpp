#include<iostream>
#include<unordered_map>
using namespace std;

const int N = 1e5 + 5;
unordered_map<int,int> mp;
int cnt = 0,f[N];
bool d[N];

int get(int x) {
    if (mp.count(x)) return mp[x];
    return mp[x] = ++cnt;
}

int find(int x) {
    if (f[x] == x) return x;
    int root = find(f[x]);
    d[x] ^= d[f[x]];
    return f[x] = root;
}

void Union(int x,int y,int s) {
    int fx = find(x),fy = find(y);
    if (fx == fy) return ;
    d[fx] = d[y] ^ d[x] ^ s,f[fx] = fy;
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= 1e5;i++) f[i] = i;
    for (int i = 1;i <= m;i++) {
        int l,r;
        string op;
        cin >> l >> r >> op;
        int x = get(l - 1),y = get(r);
        bool s = (op == "odd");
        if (find(x) != find(y)) Union(x,y,s);
        else if ((d[x] ^ d[y]) != s) {
            cout << i - 1 << endl;
            return 0;
        }
    }
    cout << m << endl;
    return 0;
}