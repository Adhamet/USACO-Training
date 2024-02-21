// CSES Task
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int n;
vector<ll> vec;

ll appleDiv(int idx, ll sum1, ll sum2) {
	if(idx == n) return abs(sum1 - sum2);

	return min(
		appleDiv(idx+1, vec[idx] + sum1, sum2),
		appleDiv(idx+1, sum1, vec[idx] + sum2)
	);
}

int main()
{
    adhamet;

    cin >> n;
    vec.resize(n);
	for(int i = 0; i < n; i++) 
		cin >> vec[i];

	cout << appleDiv(0, 0, 0) << el;

    return 0;
}