#include<iostream>
#include<map>
using namespace std;

map<string,int> a;

int main() {
    freopen("abc.in","r",stdin);
    freopen("abc.out","w",stdout);
    a["abc"] = 0;
    a["acb"] = 1;
    a["bac"] = 1;
    a["bca"] = 2;
    a["cab"] = 2;
    a["cba"] = 1;
    string s;
    cin >> s;
    cout << a[s] << endl;
    return 0;
}