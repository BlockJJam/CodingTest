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

const int MAX_V = 100;
const int INF = 987654321;

int V;
vector<pair<int, int>> adj[MAX_V];

int prim(vector<pair<int, int>> &selected)
{
	selected.clear();
	
	vector<bool> added(V, false);
	vector<int> minWeight(V, INF), parent(V, -1);
	int  ret = 0;
	minWeight[0] = parent[0] = 0;
	FOR(iter, 0, V)
	{
		int u = -1;
		FOR(v, 0, V)
		{
			if (!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
				u = v;
		}

		if (parent[u] != u)
			selected.push_back(make_pair(parent[u], u));
		ret += minWeight[u];
		added[u] = true;

		FOR(i, 0, adj[u].size())
		{
			int v = adj[u][i].first, weight = adj[u][i].second;
			if (!added[v] && minWeight[v] > weight)
			{
				parent[v] = u;
				minWeight[v] = weight;
			}
		}
	}
	return ret;
}