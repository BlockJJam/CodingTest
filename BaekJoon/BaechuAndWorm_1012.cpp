#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define Max_S 51

int T;
int M, N, k;
int k1, k2;
int graph[Max_S][Max_S] = { 0, };
bool visited[Max_S][Max_S] = { false, };
vector<int> testWormCount;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct Baechu
{
	int y, x;
};

bool isInside(int ny, int nx)
{
	return 0 <= ny && ny < N && 0 <= nx && nx < M;
}

void dfs(int y, int x)
{
	Baechu b;
	b.y = y;
	b.x = x;
	visited[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (isInside(ny, nx) && !visited[ny][nx] && graph[ny][nx] == 1)
		{
			dfs(ny, nx);
		}
	}
}

int BachuAndWorm()
{
	int wormCount = 0;
	for(int i=0; i<M; ++i)
		for (int j = 0; j < N; ++j)
		{
			if (!visited[j][i] && graph[j][i] == 1)
			{
				dfs(j, i);
				wormCount++;
			}
		}
	return wormCount;
}

int main()
{
	cin >> T;
	testWormCount = vector<int>(T, 0);
	for (int i = 0; i < T; ++i)
	{
		cin >> M >> N >> k;
		if (k > N*M || N == 0 || M == 0) return 0;

		for (int i = 0; i < k; ++i)
		{
			cin >> k1 >> k2;
			graph[k2][k1] = 1;
		}
		int wormCount = 0;
		wormCount = BachuAndWorm();
		testWormCount[i] = wormCount;

		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
			{
				visited[j][i] = false;
				graph[j][i] = false;
			}
	}
	for (int i = 0; i < testWormCount.size(); ++i)
		cout << testWormCount[i] << "\n";
	return 0;
}