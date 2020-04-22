#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_S 100
#define WALL 3

int N, M;
int graph[MAX_S][MAX_S];
int temp_graph[MAX_S][MAX_S];
int zeroCount = 0;
int tempZero = 0;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct Lab
{
	int y, x;
};
queue<Lab> q;

vector<Lab> seq;
vector<Lab> answer(3);


bool isInside(int ny, int nx)
{
	return 0 <= ny && 0 <= nx && ny < N && nx < M;
}

void bfs()
{
	while (!q.empty())
	{
		Lab lab = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = lab.x + dx[i];
			int ny = lab.y + dy[i];
			if (isInside(ny, nx) && graph[ny][nx] == 0)
			{
				graph[ny][nx] = 2;
				q.push({ ny,nx });
			}
		}
	}
}

void sequence(int n, int m)
{
	if (m == 0)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				temp_graph[i][j] = graph[i][j];

		for (int i = 0; i < 3; i++)
			graph[answer[i].y][answer[i].x] = 1;

		bfs();

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (graph[i][j] == 0)
					zeroCount += 1;

		if (tempZero < zeroCount)
			tempZero = zeroCount;

		zeroCount = 0;

		for (int i = 0; i < N; i++)	
			for (int j = 0; j < M; j++)
			{
				if (temp_graph[i][j] == 2)
					q.push({ i,j });
				graph[i][j] = temp_graph[i][j];
			}

		return;
	}
	for (int i = 0; i < n; i++)
	{
		answer[3 - m] = seq[i];
		seq.erase(seq.begin() + i);
		sequence(n - 1, m - 1);
		seq.insert(seq.begin() + i, answer[3 - m]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	seq.reserve(N*M);

	for(int i=0; i<N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 0)
			{
				seq.push_back({ i,j });
			}
			if (graph[i][j] == 2)
				q.push({ i,j });
		}

	sequence(seq.size(),3);
	cout << tempZero;
}
/*
4 4
2 0 0 1
1 0 0 0
1 1 0 1
0 0 0 2

5 5
0 0 0 1 2
1 2 0 0 0
1 1 1 1 0
0 0 0 0 0
2 0 1 0 0
*/