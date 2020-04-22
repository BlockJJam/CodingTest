#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, V;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int V)
{
	visited[V] = true;
	cout << V+1 << " ";
	for (int i = 0; i < adj[V].size(); i++)
	{
		int there = adj[V][i];
		if (!visited[there])
		{
			dfs(there);
		}
	}
}

vector<int> bfs(int start)
{
	visited[start] = true;
	queue<int> visit_list;
	vector<int> order;
	visit_list.push(start);

	while (!visit_list.empty())
	{
		int here = visit_list.front();
		visit_list.pop();
		order.push_back(here+1);

		for (int i = 0; i < adj[here].size(); ++i)
		{
			int there = adj[here][i];
			if (!visited[there])
			{
				visit_list.push(there);
				visited[there] = true;
			}
		}
	}

	return order;
}

int main1260()
{
	cin >> N >> M >> V;

	adj = vector<vector<int>>(N);
	visited = vector<bool>(N, false);

	int v1, v2;
	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2;
		adj[v1 - 1].push_back(v2 - 1);
		adj[v2 - 1].push_back(v1 - 1);
	}
	for (int i = 0; i < N; i++)
		sort(adj[i].begin(), adj[i].end());
	
	dfs(V-1);
	cout << "\n";

	visited = vector<bool>(N, false);
	vector<int> order(N,0);
	order = bfs(V - 1);
	
	for (int i = 0; i < order.size(); ++i)
		cout << order[i] <<" " ;

	return 0;
}










