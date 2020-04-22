// Shortest Distance Floyd Algo

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

#define MAX_V 100
#define INF 100

int V;
// u에서 v까지 가는 간선의 가중치( 간선이 없는 경우 매우 큰값 )
int adj[MAX_V][MAX_V];

void floyd()
{
	for (int i = 0; i < V; ++i) adj[i][i] = 0;

	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				adj[i][j] = min(adj[i][j],adj[i][k] + adj[k][j]);
}

// via[u][v]  u에서 v까지 가는 최단경로가 경유하는 점 중에 가장 큰 정점
int via[MAX_V][MAX_V];
// 모든 쌍 최단거리 알고리즘
void floyd2()
{
	for (int i = 0; i < V; i++) adj[i][i] = 0;
	memset(via, -1, sizeof(via));
	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				if (adj[i][j] > adj[i][k] + adj[k][j])
				{
					via[i][j] = k;
					adj[i][j] = adj[i][k] + adj[k][j];
				}
}

//최단 경로를 계산해 path에 저장

void reconstruct(int u, int v, vector<int>&path)
{
	if (via[u][v] == -1)
	{
		path.push_back(u);
		if (u != v) path.push_back(v);
	}
	else
	{
		int w = via[u][v];
		reconstruct(u, w, path);
		path.pop_back();
		reconstruct(w, v, path);
	}
}