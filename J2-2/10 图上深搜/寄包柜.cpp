#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5;
vector<int> G[N];

int main() {
	int n,q;
	cin >> n >> q;
	while (q--) {
		int op;
		cin >> op;
		switch (op) {
			case 1: {
				int i,j,k;
				cin >> i >> j >> k;
				if (k == 0) G[i][j] = 0;
				else {
					while (G[i].size() <= j) G[i].push_back(0);
					G[i][j] = k;
				}
				break;
			}
			case 2: {
				int i,j;
				cin >> i >> j;
				cout << G[i][j] << endl;
				break;
			}
		}
	}
    return 0;
}