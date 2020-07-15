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

template<class T>
struct OptimizedDisjointSet
{
	vector<T> parent, rank;
	OptimizedDisjointSet(T n)
		: parent(n), rank(n)
	{
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u)
	{
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);			// u가 속하는 트리의 루트를 찾았으면 그걸 parent[u]에 바로 넣어서 경로 압축 최적화 시킨다
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

const int MAX_V = 100;

int V;

vector<pair<int, int>> adj[MAX_V];

int kruskal(vector<pair<int, int>> &selected)
{
	int ret = 0;
	selected.clear();

	vector<pair<int, pair<int, int>>> edges;
	FOR(u, 0, V)
	{
		FOR(i, 0, adj[u].size())
		{
			int v = adj[u][i].first, cost = adj[u][i].second;
			edges.push_back(make_pair(cost, make_pair(u, v)));
		}
	}

	sort(edges.begin(), edges.end());
	OptimizedDisjointSet<int> sets(V);
	FOR(i, 0, edges.size())
	{
		int cost = edges[i].first;
		int u = edges[i].second.second, v = edges[i].second.second;
		
		if (sets.find(u) == sets.find(v))
			continue;

		sets.merge(u, v);
		selected.push_back(make_pair(u, v));
		ret += cost;
	}
	return ret;
}