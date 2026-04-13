#include<iostream>
#include<map>
using namespace std;

const int N = 1e6 + 5;
int f[N],d[N],ans[5];

map<int,int> job = {{'M',1},{'W',2},{'T',3},{'A',4}};

int find(int x) {
    if (f[x] == x) return x;
    int root = find(f[x]);
    d[x] = (d[x] + d[f[x]]) % 4;
    return f[x] = root;
}

void Union (int x,int y,int s) {
    int fx = find(x),fy = find(y);
    if (fx == fy) return ;
    f[fx] = fy,d[fx] = (s + d[y] - d[x] + 4) % 4;
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) f[i] = i;
    while (m--) {
        int op;
        cin >> op;
        switch (op) {
            case 0 :
                int x;
                char c;
                cin >> x >> c;
                d[x] = job[c];
                break;
            case 1 :
                int a;
                cin >> x >> a;
                Union(x,a,0);
                break;
            case 2 :
                cin >> x >> a;
                Union(x,a,3);
                break;
            case 3 :
                cin >> x >> a;
                Union(x,a,1);
                break;
            case 4 :
                cin >> x >> a;
                Union(x,a,2);
                break;
        }
    }
    for (int i = 1;i <= n;i++) {
        int x = find(i);
        ans[d[x]]++;
    }
    cout << ans[0] << ' ' << ans[3] << ' ' << ans[2] << ' ' << ans[1] << endl;
    return 0;
}