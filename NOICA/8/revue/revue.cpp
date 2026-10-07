#include<iostream>
#include<vector>
#define int long long
using namespace std;

const int N = 1e5 + 5;
struct Node {int x,y,z;} a[N];
bool vis[N];
int ans[N];

signed main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a[i].x >> a[i].y >> a[i].z;
    ans[1] = (1 << 20) - 1;
    for (auto [x,y,z] : a) {
        for (int k = 19;k >= 0;k--)
    }
    return 0;
}