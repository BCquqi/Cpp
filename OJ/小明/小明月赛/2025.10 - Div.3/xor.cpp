#include<iostream>
using namespace std;

int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int t;
    cin >> t;
    while (t--) {
        string s,a,b;
        cin >> s;
        int len = s.size();
        a.resize(len),b.resize(len);
        bool flag = false;
        for (int i = 0;i < len;i++) {
            if (s[i] == '1') {
                if (flag) a[i] = '0',b[i] = '1';
                else a[i] = '1',b[i] = '0',flag = true;
            }
            else if (s[i] == '2') {
                if (flag) a[i] = '0',b[i] = '2';
                else a[i] = '1',b[i] = '1';
            }
            else a[i] = b[i] = '0';
        }
        cout << a << endl << b << endl;
    }
    return 0;
}