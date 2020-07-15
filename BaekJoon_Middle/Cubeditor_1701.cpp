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

string target;
priority_queue<int> pq;
void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getline(cin, target);
}

vector<int> getPartialMatch()
{
	int m = target.size();
	vector<int> pi(m, 0);
	int begin = 1, matched = 0;

	while (begin + matched < m)
	{
		if (target[begin + matched] == target[matched])
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

void solve()
{
	vector<int> pi = getPartialMatch();

	FOR(i, pi.size())
	{
		pq.push(pi[i]);
	}
	cout << pq.top()<<endl;
}

int main()
{
	input();
	solve();
}