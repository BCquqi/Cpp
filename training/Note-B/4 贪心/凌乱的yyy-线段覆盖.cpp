#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 5;
struct Node {int a,b;} s[N];

int main() {
    int n,ans = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> s[i].a >> s[i].b;
    sort(s + 1,s + n + 1,[](Node x,Node y) {return x.b != y.b ? x.b < y.b : x.a < y.a;});
    int tmp = 0;
    for (int i = 1;i <= n;i++)
        if (s[i].a >= tmp) tmp = s[i].b,ans++;
    cout << ans << endl;
    return 0;
}