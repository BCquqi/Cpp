#include<iostream>
#include<map>
using namespace std;

const int N = 1e6 + 5;
int f[N],d[N],ans[5];

map<int,int> job = {{'M',0},{'W',1},{'T',2},{'A',3}};

int find(int x) {
    if (f[x] == x) return x;
    int root = find(f[x]);
    d[x] = (d[x] + d[f[x]]) % 4;
    return f[x] = root;
}

void Union (int x,int y,int s) {
    int fx = find(x),fy = find(y);
    if (fx == fy) return ;
    if (fx == 0) f[fy] = 0,d[fy] = (d[x] - s - d[y] + 8) % 4;
    else f[fx] = fy,d[fx] = (s + d[y] - d[x] + 4) % 4;
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
                Union(x,0,job[c]);
                break;
            case 1 :
            	int a;
            	cin >> x >> a;
                Union(x,a,0);
                break;
            case 2 :
            	cin >> x >> a;
                Union(x,a,1);
                break;
            case 3 :
            	cin >> x >> a;
                Union(x,a,3);
                break;
            case 4 :
            	cin >> x >> a;
                Union(x,a,2);
                break;
        }
    }
    int root0 = find(0);
    for (int i = 1;i <= n;i++)
        if (find(i) == root0) ans[d[i]]++;
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << endl;
    return 0;
}