#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <bitset>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;

#define FOR(i,n) for(int i=0; i<(n); i++)
#define endl "\n"
#define ll unsigned long long

int N, M;
vector<string> target;
vector<string> pat;
bool isMatch[100001];
int match_count = 0;

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	FOR(i, N)
	{
		string n;
		cin >> n;
		target.push_back(n);
	}

	FOR(i, M)
	{
		string m;
		cin >> m;
		pat.push_back(m);
	}
}

void solve()
{
	FOR(i, M)
	{
		FOR(j, N)
		{
			int comp = pat[i].size();
			bool is_match = true;
			//cout << "compare: " << comp_end << endl;
			if (pat[i][comp - 1] != target[j][comp - 1] && comp > target[j].size())
				continue;
			FOR(k, comp)
			{
				if (pat[i][k] != target[j][k])
				{
					is_match = false;
					break;
				}
			}
			
			if (is_match == true)
			{
				isMatch[i] = true;
				break;
			}
		}
	}

	FOR(i, M)
	{
		if (isMatch[i] == true)
			match_count++;
	}
	cout << match_count << endl;
}

int main()
{
	input();
	solve();

	return 0;
}
/*
5 10
baekjoononlinejudge
startlink
codeplus
sundaycoding
codingsh
baekjoon
star
start
code
sunday
coding
cod
online
judge
plus
*/