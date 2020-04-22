#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_S 1001

vector<vector<int>> graph;
int N, M;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct Tomato
{
	int y, x;
};

queue<Tomato> q;

bool isInside(int ny, int nx)
{
	return 0 <= ny && 0 <= nx && ny < N && nx < M;
}

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (isInside(ny, nx) && graph[ny][nx] == 0)
			{
				graph[ny][nx] = graph[y][x] + 1;
				//cout << "{" << nx << "," << ny << "}";
				q.push({ ny, nx });
			}
		}
	}
}

int main()
{
	graph = vector<vector<int>>(MAX_S, vector<int>(MAX_S));

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
		{
			cin >> graph[j][i];
			if (graph[j][i] == 1)
				q.push({ j,i });
		}
	
	bfs();

	int result = 0;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
		{
			if (graph[j][i] == 0)
			{
				cout << "-1";
				return 0;
			}
			else if (result < graph[j][i])
				result = graph[j][i];
		}
	cout << result-1;

	return 0;
}