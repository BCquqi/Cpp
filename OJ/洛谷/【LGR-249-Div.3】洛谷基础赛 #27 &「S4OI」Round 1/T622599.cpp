#include<iostream>
using namespace std;

const int N = 105;
int a[N];

int main() {
    int n,m,k,l,r;
    cin >> n >> m >> k >> l >> r;
    for (int i = 1;i <= k;i++) {
        int x,y,v;
        cin >> x >> y >> v;
        if (v <= l) a[x] += 100;
        else if (v >= r) a[x] += 0;
        else a[x] += v;
    }
    for (int i = 1;i <= n;i++) cout << a[i] << ' ';
    cout << endl;
    return 0;
}