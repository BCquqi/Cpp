#include<iostream>
#include<iomanip>
using namespace std;

const int N = 1005;
int id[N];

int main() {
    freopen("entrycode.in","r",stdin);
    freopen("entrycode.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cout << setfill('0');
    for (int i = 1;i <= n;i++) {
        string s;
        int x;
        cin >> s >> x;
        cout << s << setw(3) << x << setw(5) << ++id[x] << endl;
    }
    return 0;
}