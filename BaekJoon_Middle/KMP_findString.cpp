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

string target, part;
vector<int> match_index;
int ans_count = 0;

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getline(cin,target);
	getline(cin,part);
}

vector<int> getPartialMatch()
{
	int m = part.size();
	vector<int> pi(m, 0);
	int begin = 1, matched = 0;
	while (begin + matched < m)
	{
		if (part[begin + matched] == part[matched])
		{
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else
		{
			if (matched == 0)
				++begin;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

void findPartialString()
{
	int n = target.size();
	int m = part.size();
	int begin = 0, matched = 0;
	vector<int> pi = getPartialMatch();
	
	while (begin <= n - m)
	{
		//cout << "begin: " << begin << endl;
		if (matched < m && target[begin + matched] == part[matched])
		{
			++matched;
			if (matched == m)
			{
				ans_count++;
				match_index.push_back(begin+1);
			}
		}
		else
		{
			if (matched == 0)
				++begin;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
}

void solve()
{
	findPartialString();
	cout << ans_count << endl;
	FOR(i, match_index.size())
		cout << match_index[i] << " ";
}
int main()
{
	input();
	solve();

	return 0;
}