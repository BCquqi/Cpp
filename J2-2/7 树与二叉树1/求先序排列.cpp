#include<iostream>
using namespace std;

string m,b;

void dfs(int l,int r,int t) { // t表示根在后序的编号
    if (l > r) return ;
    char root = b[t];
    int pos = l;
    for (int i = l; i <= r; i++)
        if (m[i] == root)
            pos = i;
    cout << root;
    dfs(l,pos - 1,t - (r - pos) - 1);
    dfs(pos + 1,r,t - 1);
}

int main() {
    cin >> m >> b;
    int len = m.size();
    m = '?' + m;
    b = '?' + b;
    dfs(1,len,len);
    cout << endl;
    return 0;
}