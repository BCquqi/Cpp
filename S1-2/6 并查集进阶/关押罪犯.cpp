#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
struct Node {int a,b,c;} s[N];
int f[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void Union(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx != fy) f[fx] = fy;
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= 2 * n;i++) f[i] = i;
    for (int i = 1;i <= m;i++)
        cin >> s[i].a >> s[i].b >> s[i].c;
    sort(s + 1,s + m + 1,[](Node x,Node y) {return x.c > y.c;});
    for (int i = 1;i <= m;i++) {
        int a = s[i].a,b = s[i].b,c = s[i].c;
        if (find(a) == find(b)) {cout << c << endl; return 0;}
        else {Union(a,b + n); Union(b,a + n);}
    }
    cout << 0 << endl;
    return 0;
}