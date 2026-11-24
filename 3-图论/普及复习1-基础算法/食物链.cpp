#include<iostream>
using namespace std;

const int N = 5e4 + 5;
int f[3 * N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void Union(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx != fy) f[fx] = fy;
}

int main() {
    int n,k,ans = 0;
    cin >> n >> k;
    for (int i = 1;i <= 3 * n;i++) f[i] = i;
    for (int i = 1;i <= k;i++) {
        int op,x,y;
        cin >> op >> x >> y;
        if (x > n || y > n) {
            ans++;
            continue;
        }
        if (op == 1) {
            if (find(x) == find(y + n) || find(y) == find(x + n)) ans++;
            else {Union(x,y); Union(x + n,y + n); Union(x + 2 * n,y + 2 * n);}
        } else {
            if (find(x) == find(y) || find(y) == find(x + 2 * n)) ans++;
            else {Union(x,y + 2 * n); Union(x + n,y); Union(x + 2 * n,y + n);}
        }
    }
    cout << ans << endl;
    return 0;
}