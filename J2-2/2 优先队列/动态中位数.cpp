#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

priority_queue<int> L;
priority_queue<int,vector<int>,greater<int> > R;

int main() {
    int n,mid;
    cin >> n >> mid;
    cout << mid << endl;
    for (int i = 2;i <= n;i++) {
        int a;
        cin >> a;
        if (i % 2 == 0) {
            if (a < mid) L.push(a),R.push(mid);
            else R.push(a),L.push(mid);
        }
        else {
            if (a < L.top()) {mid = L.top(); L.pop(); L.push(a);}
            else if (a > R.top()) {mid = R.top(); R.pop(); R.push(a);}
            else mid = a;
            cout << mid << endl;
        }
    }
    return 0;
}