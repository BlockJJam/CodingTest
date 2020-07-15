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

int N, M;
int graph[501][501];
bool visited[501][501];
int answer = 0;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

bool isInside(int ny, int nx)
{
	return ny >= 0 && nx >= 0 && ny < N && nx < M;
}

void solve(int by, int bx, int cnt, int point)
{
	if (cnt == 4)
	{
		answer = answer < point ? point : answer;
		return;
	}
	if (cnt == 1)
	{
		FOR(i, 0, 4)
		{
			int ny1 = by + dy[i], nx1 = bx + dx[i];
			int ny2 = by + dy[(i + 1) % 4], nx2 = bx + dx[(i + 1) % 4];

			if (isInside(ny1, nx1) && isInside(ny2, nx2) && visited[ny1][nx1] == false && visited[ny2][nx2] == false)
			{
				int comp_point = point + graph[by][bx] + graph[ny1][nx1] + graph[ny2][nx2];
				answer = answer < comp_point ? comp_point : answer;
			}
		}
	}
	FOR(i, 0, 4)
	{
		int ny = by + dy[i];
		int nx = bx + dx[i];

		if (isInside(ny, nx) && visited[ny][nx] == false)
		{
			visited[ny][nx] = true;
			solve(ny, nx, cnt + 1, point + graph[by][bx]);
			visited[ny][nx] = false;
		}
	}
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	FOR(i, 0, N)
	{
		FOR(j, 0, M)
		{
			cin >> graph[i][j];
		}
	}
}

int main()
{
	input();
	
	FOR(i ,0, N)
	{
		FOR(j ,0, M)
		{
			visited[i][j] = true;
			solve(i, j, 0, 0);
			visited[i][j] = false;
		}
	}

	cout << answer << endl;
}