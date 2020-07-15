#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

#define FOR(i,n,m) for(int i=(n); i<(m); i++)

int N;
unordered_set<int> cache[10];
unordered_set<int> solve(int n)
{
	if (!cache[n].empty()) return cache[n];
	int num = 0;
	for (int i = 0; i < n; i++) num = 10 * num + N;
	unordered_set<int> res;
	res.insert(num);
	for (int i = 1; i < n; i++)
	{
		int j = n - 1;
		auto s1 = solve(i);
		auto s2 = solve(j);
		for (int n1 : s1)
		{
			for (int n2 : s2)
			{
				res.insert(n1 + n2);
				res.insert(n1 - n2);
				res.insert(n1 * n2);
				if (n2 != 0) res.insert(n1 / n2);
			}
		}
	}
	return cache[n] = res;
}

int solution(int _N, int number)
{
	N = _N;
	for (int i = 1; i <= 8; i++)
	{
		solve(i);
		if (cache[i].find(number) != cache[i].end()) return i;
	}
	return -1;
}

