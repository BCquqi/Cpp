#include<iostream>
#include<algorithm> 
using namespace std;

struct Student {
	string name;
	int cj,bj,lw;
	bool gb,xb;
	int money,id;
} a[105];

bool cmp(Student x,Student y)
{
	if (x.money != y.money) return x.money > y.money;
	else return x.id < y.id;
}

int main()
{
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1;i <= n;i++)
	{
		a[i].id = i;
		cin >> a[i].name >> a[i].cj >> a[i].bj;
		char gb,xb;
		cin >> gb >> xb;
		if (gb == 'Y') a[i].gb = true;
		if (gb == 'N') a[i].gb = false;
		if (xb == 'Y') a[i].xb = true;
		if (xb == 'N') a[i].xb = false;
		cin >> a[i].lw;
		if (a[i].cj > 80 && a[i].lw >= 1) a[i].money += 8000;
		if (a[i].cj > 85 && a[i].bj >= 80) a[i].money += 4000;
		if (a[i].cj > 90) a[i].money += 2000;
		if (a[i].cj > 85 && a[i].xb) a[i].money += 1000;
		if (a[i].bj > 80 && a[i].gb) a[i].money += 850;
		sum += a[i].money;
	}
	sort(a + 1,a + n + 1,cmp);
	cout << a[1].name << endl;
	cout << a[1].money << endl;
	cout << sum << endl;
	return 0;
}
