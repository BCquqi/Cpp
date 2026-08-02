#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int n,len[N];

int init() {
    int i;
    len[0] = 3;
    for (i = 1;len[i - 1] < n;i++)
        len[i] = (len[i - 1] * 2) + i + 3;
    return i - 1;
}

void merge(int p,int q) {
    if (p == 0) {
        cout << (q == 1 ? 'm' : 'o') << '\n';
        return;
    }
    while (len[p - 1] > q) p--;
    if (q == len[p - 1] + 1) {
        cout << 'm' << endl;
        return ;
    }
    else if  (q <= len[p - 1] + p + 3) {
        cout << 'o' << endl;
        return ;
    }
    merge(p - 1,q - len[p - 1] - p - 3);
}

int main() {
    cin >> n;
    merge(init(),n);
    return 0;
}