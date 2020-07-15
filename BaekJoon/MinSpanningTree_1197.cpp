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

const int MAX_V = 10001;

int V,E;
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
	OptimizedDisjointSet<int> sets(V+1);

	FOR(i, 0, edges.size())
	{
		
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		
		if (sets.find(u) == sets.find(v))
			continue;
		sets.merge(u, v);
		selected.push_back(make_pair(u, v));
		//cout << cost << " " << u << "," << v << endl;
		ret += cost;
	}
	
	return ret;
}

const int INF = 7654321;
int prim(vector<pair<int, int>> &selected,int start)
{
	selected.clear();
	//cout << start << endl;

	vector<bool> added(V+1, false);
	added[0] = true;
	vector<int> minWeight(V+1, INF), parent(V+1, -1);
	int ret = 0;
	minWeight[start]= 0; parent[start] = start;

	FOR(iter, 0, V)
	{
		
		int u = -1;
		FOR(v, 1, V+1)
		{
			
			int loop = (start + v-1) % (V+1);
			if (loop < start)++loop;
			
			if (!added[loop] && (u == -1 || minWeight[u] > minWeight[loop]))
				u = loop;
		}
		//cout << u  << " " <<  minWeight[u]<< endl;
		if (parent[u] != u)
			selected.push_back(make_pair(parent[u], u));

		if(minWeight[u] != INF)
			ret += minWeight[u];
		added[u] = true;
		FOR(i, 0, adj[u].size())
		{
			
			int v = adj[u][i].first, weight = adj[u][i].second;
			//cout << "near " << v << "," << weight << endl;
			if (!added[v] && minWeight[v] > weight)
			{
				parent[v] = u;
				minWeight[v] = weight;
			}
		}
	}
	return ret;
}


void input(int &start)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	int a, b, c;
	FOR(i, 0, E)
	{
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	start = a;
}

int main()
{
	int start = 0;
	input(start);
	vector<pair<int, int>> selected;
	// 크루스칼
	//int answer = kruskal(selected);
	
	//프림
	int answer = prim(selected, start);
	cout << answer;
}