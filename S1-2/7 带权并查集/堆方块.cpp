#include<iostream>
using namespace std;

const int N = 3e4 + 5;
int f[N],s[N],siz[N];

int find(int x) {
    if (f[x] == x) return x;
    int root = find(f[x]);
    s[x] += s[f[x]];
    return f[x] = root;
}

void Union(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx == fy) return ;
    s[fx] += siz[fy],siz[fy] += siz[fx],f[fx] = fy;
}

int main() {
    int p;
    cin >> p;
    for (int i = 1;i <= 30000;i++) f[i] = i,siz[i] = 1;
    while (p--) {
        char op;
        cin >> op;
        if (op == 'M') {
            int x,y;
            cin >> x >> y;
            Union(x,y);
        } else {
            int x;
            cin >> x;
            find(x);
            cout << s[x] << endl;
        }
    }
    return 0;
}