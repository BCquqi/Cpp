#include<iostream>
using namespace std;

const int N = 2005;
struct Range {int l,r;} a[N];

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
        cin >> a[i].l >> a[i].r;
    sort(a + 1,a + m + 1,[](Range x,Range y) {return (x.l != y.l ? x.l < y.l : x.r > y.r);});
    return 0;
}