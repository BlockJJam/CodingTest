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
#include <limits>
using namespace std;

#define FOR(i,m,n) for(int i=(m); i<(n); i++)

int N, M, K;
char graph[1001][1001];
bool visited[1001][1001][11];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int answer = -1;

struct Node
{
	int y, x, wall, dist;
};

queue<Node> q;

bool isInside(int ny, int nx)
{
	return ny >= 0 && nx >= 0 && ny < N && nx < M;
}

void bfs(int k)
{
	q.push({ 0,0,k,1 });
	visited[0][0][k] = true;

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int wall = q.front().wall;
		int dist = q.front().dist;
		q.pop();

		if (answer != -1)
			if (answer < dist)
				continue;

		if (y == N - 1 && x == M - 1)
		{
			if (answer == -1)
				answer = dist;
			else
				answer = answer < dist ? answer : dist;
		}

		FOR(i, 0, 4)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (isInside(ny, nx) && visited[ny][nx][wall] == false)
			{
				if (graph[ny][nx] == '1')
				{
					if (wall > 0)
					{
						visited[ny][nx][wall] = true;
						q.push({ ny,nx,wall - 1, dist + 1 });
					}
				}
				else
				{
					visited[ny][nx][wall] = true;
					q.push({ ny,nx,wall,dist + 1 });
				}
			}
		}
	}
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	char c;
	FOR(i, 0, N)
		FOR(j, 0, M)
		cin >> graph[i][j];

}

int main()
{
	input();
	bfs(K);

	cout << answer << endl;
	return 0;
}