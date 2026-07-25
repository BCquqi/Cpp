#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5e4 + 5;
struct Node {int a,b;} s[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
        cin >> s[i].a >> s[i].b;
    sort(s + 1,s + n + 1,[](Node x,Node y) {return x.a < y.a;});
    int l = s[1].a,r = s[1].b;
    for (int i = 2;i <= n;i++) {
        if (s[i].a <= r) r = max(r,s[i].b);
        else {
            cout << l << ' ' << r << endl;
            l = s[i].a,r = s[i].b;
        }
    }
    cout << l << ' ' << r << endl;
    return 0;
}