#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
    freopen("lab.in","r",stdin);
    freopen("lab.out","w",stdout);
    int n;
    cin >> n;
    int minx = 1e9,maxx = 0,miny = 1e9,maxy = 0;
    for (int i = 1;i <= n;i++) {
        int x,y;
        cin >> x >> y;
        maxx = max(maxx,x), minx = min(minx,x);
        maxy = max(maxy,y), miny = min(miny,y);
    }
    cout << minx - 1 << ' ' << miny - 1 << endl << maxx + 1 << ' ' << maxy + 1 << endl;
    return 0;
}