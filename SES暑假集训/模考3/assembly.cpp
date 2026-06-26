#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    freopen("assembly.in","r",stdin);
    freopen("assembly.out","w",stdout);
    int n;
    long long a = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        string s; int x;
        cin >> s;
        if (s == "inc") {
            char c;
            cin >> c;
            a++;
        } else if (s == "dec") {
            char c;
            cin >> c;
            a--;
        } else if (s == "add") {
            char c1,c2;
            cin >> c1 >> c2 >> x;
            a += x;
        } else {
            char c1,c2;
            cin >> c1 >> c2 >> x;
            a -= x;
        }
    }
    cout << a << endl;
    return 0;
}