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

    int n;	cin >> n;

    vector<int> perm;

    // Automatically sorted.
    for(int i = 0; i < n; i++) {
    	perm.push_back(i);
    }

    do {
    	for(int i = 0; i < perm.size(); i++) {
    		cout << perm[i] << " ";
    	}
    	cout << el;
    } while(next_permutation(perm.begin(),perm.end()));
	
    return 0;
}