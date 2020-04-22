//BFS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

class State
{
public:
	vector<State> getAdjacent() const;
	bool operator < (const State& rhs) const;
	bool operator == (const State& rhs) const;
};
typedef map<State, int> StateMap;

// 기본 BFS
int bfs(State start, State finish)
{
	if (start == finish) return 0;
	StateMap c;

	queue<State> q;
	q.push(start);
	c[start] = 0;

	while (!q.empty())
	{
		State here = q.front();
		q.pop();
		int cost = c[here];

		vector<State> adjacent = here.getAdjacent();
		for (int i = 0; i < adjacent.size(); ++i)
		{
			if (c.count(adjacent[i]) == 0)
			{
				if (adjacent[i] == finish) return cost + 1;
				c[adjacent[i]] = cost + 1;
				q.push(adjacent[i]);
			}
		}
	}
	return -1;
}

//양방향 BFS
int sgn(int x) { if (!x) return 0; return x > 0 ? 1 : -1; }
int incr(int x) { if (x < 0) return x - 1; return x + 1; }

int bidirectional(State start, State finish)
{
	map<State, int> c;
	queue<State> q;

	if (start == finish) return 0;
	
	q.push(start); c[start] = 1;
	q.push(finish); c[finish] - 1;
	
	while (!q.empty())
	{
		State here = q.front();
		q.pop();
		vector<State> adjacent = here.getAdjacent();
		for (int i = 0; i < adjacent.size(); i++)
		{
			map<State, int>::iterator it = c.find(adjacent[i]);
			if (it == c.end())
			{
				c[adjacent[i]] = incr(c[here]);
				q.push(adjacent[i]);
			}
			else if (sgn(it->second) != sgn(c[here]))
				return abs(it->second) + abs(c[here]) - 1;
		}
	}
	return -1;
}

// 점점 깊어지는 탐색
class State;
int best;

void dfs(State here, const State& finish, int steps)
{
	if (steps >= best) return;

	if (here == finish) { best = steps; return; }

	vector<State> adjacent = here.getAdjacent();
	for (int i = 0; i < adjacent.size(); ++i)
		dfs(adjacent[i], finish, steps + 1);
}

int ids(State start, State finish, int growthStep)
{
	for (int limit = 4; ; limit += growthStep)
	{
		best = limit + 1;
		dfs(start, finish, 0);
		dfs(start, finish, 0);
		if (best <= limit) return best;
	}
	return -1;
}