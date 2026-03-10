#include<iostream>
#include<list>
using namespace std;

const int N = 1005;
list<int> ls[N];

int main() {
	int n,m;
	cin >> n >> m;
	while (m--) {
		string op;
		cin >> op;
		if (op == "add") {
			int x,a,b; bool d;
			cin >> x >> a >> b >> d;
			if (!d) while (b--) ls[x].push_front(a);
			else while (b--) ls[x].push_back(a);
		}
		else if (op == "remove") {
			int x,a;
			cin >> x >> a;
			ls[x].remove(a);
		}
		else if (op == "move") {
			int x,y; bool d;
			cin >> x >> y >> d;
			if (!d) ls[y].splice(ls[y].begin(),ls[x]);
			else ls[y].splice(ls[y].end(),ls[x]);
		}
		else if (op == "reverse") {
			int x;
			cin >> x;
			ls[x].reverse();
		}
		else if (op == "query") {
			int x;
			cin >> x;
			for (auto t : ls[x]) cout << t << ' ';
			cout << endl;
		}
	}
	return 0;
}