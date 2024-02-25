// CSES - Task 1622
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

int main()
{
    adhamet;

    string s;	cin >> s;

    sort(s.begin(), s.end());

    vector<string> permutations;
    do {
    	permutations.push_back(s);
    } while(next_permutation(s.begin(),s.end()));
	
	cout << permutations.size() << el;
	for(const string& permutation: permutations)
		cout << permutation << el;

    return 0;
}