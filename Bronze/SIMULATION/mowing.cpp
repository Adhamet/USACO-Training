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

bool vis[1000][1000] = {false};
int second = 0;
int mowed_at_second[1000][1000] = {0};
vector<int> savedTimes;

void action(char D, int& x, int& y) {
    D == 'N' ? x -= 1 : D == 'S' ? x += 1 : D == 'W' ? y -= 1 : y += 1;
    if (vis[x][y])
        savedTimes.push_back(second - mowed_at_second[x][y]);
    vis[x][y] = true;
    mowed_at_second[x][y] = second;
    second++;
}

int main()
{
    adhamet;
	setIO("mowing");
    vis[500][500] = true;
    
    int n;  cin >> n;
    
    char D;
    int S;
    
    int x=500,y=500;
    for(int i = 0; i < n; i++) {
        cin >> D >> S;
        for(int i = 0; i < S; i++)
            action(D,x,y);
    }
    
    int mn = INT_MAX;
    for(const auto &itm: savedTimes)
        mn = min(mn, itm);
    cout << (mn == INT_MAX ? -1 : mn);

    return 0;
}