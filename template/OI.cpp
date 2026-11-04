namespace OI {

	// init the prefix sum array
	void init_prefix_sum(const int a[], int s[], const int start_pos, const int n) {
		int cur = start_pos;
		s[0] = 0;
		for (int i = 0; i < n; ++i) {
			const auto& it = a[i];
			s[++cur] = s[cur - 1] + it;
		}
	}

	// query the sum of the raw array in range [l,r]
	inline int query_prefix_sum(const int s[], int l, int r) {
		return s[r] - s[l - 1];
	}

	// init the difference array
	void init_difference(const int a[], int d[], const int start_pos, const int n) {
		int cur = start_pos, last = 0;
		for (int i = 0; i < n; ++i) {
			const auto& it = a[i];
			d[++cur] = it - last, last = it;
		}
	}

	// add on the raw array in range [l,r] with value val
	void modify_difference(int d[], int l, int r, const int& val) {
		d[l] += val, d[r + 1] -= val;
	}

	// get the final array
	inline int* query_difference(const int d[], const int n) {
		int* ret = new int[n];
		int tmp = 0;
		for (int i = 0; i < n; ++i) {
			tmp += d[i];
			ret[i] = tmp;
		}
		return ret;
	}
	
	
}
