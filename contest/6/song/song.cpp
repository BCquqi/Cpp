#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    freopen("song.in","r",stdin);
    freopen("song.out","w",stdout);
    string s;
    long long c;
    cin >> s >> c;
    c++;
    int len = s.size();
    s = '?' + s;
    char ch = s[1];
    long long tmp = 0,sum = 0;
    for (int i = 1;i <= len;i++)
        if ('0' <= s[i] && s[i] <= '9') tmp = tmp * 10 + (s[i] - '0');
        else sum += tmp,tmp = 0,ch = s[i];
    sum += tmp,tmp = 0;
    c %= sum;
    if (c == 0) {
        cout << ch << endl;
        return 0;
    }
    ch = s[1];
    for (int i = 1;i <= len;i++)
        if ('0' <= s[i] && s[i] <= '9') tmp = tmp * 10 + (s[i] - '0');
        else {
            c -= tmp,tmp = 0;
            if (c <= 0) {
                cout << ch << endl;
                return 0;
            }
            ch = s[i];
        }
    c -= tmp,tmp = 0;
    if (c <= 0) {
        cout << ch << endl;
        return 0;
    }
    return 0;
}