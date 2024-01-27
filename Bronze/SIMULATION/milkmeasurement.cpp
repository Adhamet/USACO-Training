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

void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);	
	}
}

int main()
{
    adhamet;
	setIO("measurement");
    
	map<int, pair<string, int>> mapOfInput;

	int n;	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		string s;
		char op;
		int y;
		cin >> x >> s >> op >> y;

		if(op == '-') y = -y;
		mapOfInput[x] = {s,y};
	}

	int Bessie = 7, Elsie = 7, Mildred = 7;
	int oldBessie, oldElsie, oldMildred;
	int globalMax = 0, localMax = 7;
	int chng = 0;
	for(auto const &cow : mapOfInput) {
		if(cow.second.first == "Bessie") {
			oldBessie = Bessie;
			Bessie += cow.second.second;
			if ( (oldBessie == Elsie || oldBessie == Mildred) && oldBessie == globalMax)
				chng++;
			else if ( (Bessie == Elsie || Bessie == Mildred) && Bessie == globalMax) 
				chng++;
		}
		else if(cow.second.first == "Elsie") {
			oldElsie = Elsie;
			Elsie += cow.second.second;
			if ( (oldElsie == Bessie || oldElsie == Mildred) && oldMildred == globalMax)
				chng++;
			else if ( (Elsie == Bessie || Elsie == Mildred) && Elsie == globalMax) 
				chng++;
		}
		else if(cow.second.first == "Mildred") {
			oldMildred = Mildred;
			Mildred += cow.second.second;
			if ( (oldMildred == Bessie || oldMildred == Elsie) && oldMildred == globalMax)
				chng++;
			else if ( (Mildred == Bessie || Mildred == Elsie) && Mildred == globalMax)
				chng++;

		}
		
		localMax = max( {Bessie, Elsie, Mildred} );
		if (globalMax != localMax) {
			chng++;
			globalMax = localMax;
		}
	}
	cout << chng;

    return 0;
}