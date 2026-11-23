int L = 1,R = 1e9,ans = -1;
while (L <= R)
{
	int mid = L + R >> 1;
	if (check(mid))
	{
		L = mid + 1;
		ans = mid;
	}
	else R = mid - 1;
}
cout << ans << endl;

// or

int L = 1,R = 1e9,ans = -1;
while (L <= R)
{
	int mid = L + R >> 1;
	if (check(mid))
	{
		R = mid - 1;
		ans = mid;
	}
	else L = mid + 1;
}
cout << ans << endl;
