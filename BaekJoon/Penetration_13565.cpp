#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int graph[1001][1001];
bool visited[1001][1001];
bool result=false;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool isInside(int ny, int nx)
{
	return ny >= 0 && nx >= 0 && ny < N && nx < M;
}

void dfs(int y, int x)
{
	if (y == N-1)
		result = true;

	if(result == true)
		return;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (isInside(ny, nx) && visited[ny][nx] == false)
		{
			visited[ny][nx] = true;
			dfs(ny, nx);
		}
	}
}

void solve()
{
	for (int i = 0; i < M; i++)
	{
		if (visited[0][i] == false)
		{
			visited[0][i] = true;
			dfs(0, i);
		}

		for(int i=0; i<N; i++)
			for (int j = 0; j < M; j++)
			{
				if (graph[i][j] == 1)
					visited[i][j] = true;
				else
					visited[i][j] = false;
			}
	}

	if (result == true)
		cout << "YES";
	else
		cout << "NO";
}

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			graph[i][j] = s[j] - '0';
			if (graph[i][j] == 1)
				visited[i][j] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	input();
	solve();

	return 0;
}