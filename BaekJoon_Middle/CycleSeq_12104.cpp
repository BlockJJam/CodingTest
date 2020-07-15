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

string target, part;
int match_count = 0;

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getline(cin, part);
	getline(cin, target);
}

vector<int> getPartialMatch(string& pattern)
{
	int m = pattern.size();
	vector<int> pi(m, 0);
	int begin = 1, matched = 0;
	while (begin + matched < m)
	{
		if (pattern[begin + matched] == pattern[matched])
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

void kmp(string& B, string &A)
{
	int n = B.size();
	int m = A.size();
	vector<int> pi = getPartialMatch(A);
	int begin = 0, matched = 0;
	
	while (begin <= n - m)
	{
		if (matched < m && B[begin + matched] == A[matched])
		{
			++matched;
			if (matched == m)
			{
				++match_count;
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
	string A, B;
	A = part;
	B = target + target;
	string BB = B.substr(0, B.size() - 1);
	kmp(BB, A);
	
	cout << match_count << endl;
}

int main()
{
	input();
	solve();

	return 0;
}