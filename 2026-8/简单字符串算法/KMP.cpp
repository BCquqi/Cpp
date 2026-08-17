#include<iostream>
using namespace std;

const int N = 2e6 + 5;
int prefix[N];

void init(string s) {
    int len = s.size();
    for (int i = 1;i < len;i++) {
        int j = prefix[i - 1];
        while (j > 0 && s[i] != s[j]) j = prefix[j - 1];
        if (s[i] == s[j]) j++;
        prefix[i] = j;
    }
    return ;
}

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    int len1 = s1.size(),len2 = s2.size();
    string t = s2 + '#' + s1;
    init(t);
    for (int i = len2 + 1;i <= len1 + len2;i++)
        if (prefix[i] == len2) cout << i - 2 * len2 + 1 << endl;
    init(s2);
    for (int i = 0;i < len2;i++) cout << prefix[i] << ' ';
    cout << endl;
    return 0;
}