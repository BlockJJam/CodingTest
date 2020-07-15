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

#define FOR(i,m,n) for(int i=(m); i<(n); i++)
#define endl "\n"
#define ll long long

struct DisjointSet
{
	vector<int> parent, rank;
	DisjointSet(int n)
		: parent(n+1), rank(n+1)
	{
		FOR(i, 1, n+1)
		{
			parent[i] = i;
		}
	}

	int find(int u)
	{
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v)
	{
		u = find(u); v = find(v);
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) ++rank[v];
	}
};

int graph[201][201];
int N, M; 
vector<int> plan;

void solve(DisjointSet& ds)
{
	int start = ds.find(plan[0]);
	//cout << start << endl;
	FOR(i, 1, plan.size())
	{
		int next = ds.find(plan[i]);
		if (start != next)
		{
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	DisjointSet ds{ N };

	FOR(i, 0, N)
		FOR(j, 0, N)
	{
		cin >> graph[i][j];
		if (graph[i][j] == 1)
		{
			ds.merge(i+1, j+1);
		}
	}

	int a;
	FOR(i, 0, M)
	{
		cin >> a;
		plan.push_back(a);
	}
	

	solve(ds);
}

int main()
{
	input();

	return 0;
}