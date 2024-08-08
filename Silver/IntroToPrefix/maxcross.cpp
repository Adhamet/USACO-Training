#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 2e5+10;

int main() {
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	
	int n, k, b;
	cin >> n >> k >> b;

	unordered_map<int, bool> broken;
	for (int i = 0; i < b; i++) {
		int x;
		cin >> x;
		broken[x] = true;
	}

	vector<int> pref(n + 1);
	pref[0] = 0;

	vector<int> vec(n);
	iota(vec.begin(), vec.end(), 1);
	
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1];
		if (broken[vec[i - 1]]) pref[i] += 1;
	}

	int l = 1, r = l + k - 1, ans = 1e9;
	while (r < n) {
		ans = min(ans, pref[r] - pref[l - 1]);
		
		l += 1;
		r = l + k - 1;
	}

	cout << ans << el;
	
	return 0;
}
