// Shortest Distance Algo

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <limits.h>

using namespace std;

#define MAX_V 100
#define INF 100

int V;
vector<pair<int, int>> adj[MAX_V];

// 우선순위 큐사용 다익스트라
vector <int> dijkstra(int src)
{
	vector<int> dist(V, INF);
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		
		for (int i = 0; i < adj[here].size(); ++i)
		{
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;

			if (dist[there] > nextDist)
			{
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}

// 우선순위 큐 없는 다익스트라

vector<int> dijkstra2(int src)
{
	vector<int> dist(V, INF);

	vector<bool> visited(V, false);
	dist[src] = 0; visited[src] = false;
	while (true)
	{
		int closest = INF, here;
		for(int i=0; i<V; ++i)
			if (dist[i] < closest && !visited[i])
			{
				here =i; 
				closest =dist[i];
			}
		if (closest == INF) break;

		for (int i = 0; i < adj[here].size(); ++i)
		{
			int there = adj[here][i].first;
			if (visited[there]) continue;
			int nextDist = dist[here] + adj[here][i].second;
			dist[there] = min(dist[there], nextDist);
		}
	}
	return dist;
}

// 벨만 포드 알고리즘

vector <pair<int, int>> adj2[MAX_V];

vector<int> bellmanFor(int src)
{
	vector<int> upper(V, INF);
	upper[src] = 0;
	bool updated;

	for (int iter = 0; iter < V; ++iter)
	{
		updated = false;
		for (int here = 0; here < V; ++here)
			for (int i = 0; i < adj2[here].size(); i++)
			{
				int there = adj2[here][i].first;
				int cost = adj2[here][i].second;
				if (upper[there] > upper[here] + cost)
				{
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}

		if (!updated)break;
	}
	if (updated) upper.clear();
	return upper;
}