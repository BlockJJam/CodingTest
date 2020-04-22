#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int A, B;
int x, y;

bool visited[101] = { false, };
int depth[101] = { 0, };
int graph[101][101];
queue<int> q;

void bfs(int A)
{
	visited[A] = true;
	q.push(A);

	while (!q.empty())
	{
		int a = q.front();
		q.pop();

		for (int j = 1; j <= N; j++)
		{
			if (graph[a][j] == 1 && !visited[j])
			{
				visited[j] = true;
				depth[j] = depth[a] + 1;
				q.push(j);
			}
		}
	}

}

int main()
{
	cin >> N;
	cin >> A >> B;
	cin >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	bfs(A);

	if (depth[B] != 0)
		cout << depth[B] << "\n";
	else
		cout << -1 << "\n";

}