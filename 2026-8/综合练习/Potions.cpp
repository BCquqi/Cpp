#include<iostream>
#include<queue>
using namespace std;

priority_queue<int,vector<int>,greater<int> > q;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    long long sum = 0;
    for (int i = 1;i <= n;i++) {
        int a;
        cin >> a;
        if (a > 0) ans++, sum += a;
        else {
            sum += a;
            q.push(a);
            if (sum < 0) sum -= q.top(), q.pop();
            else ans++;
        }
    }
    cout << ans << endl;
    return 0;
}