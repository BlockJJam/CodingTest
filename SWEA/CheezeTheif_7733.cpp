#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int T, N;
int graph[101][101];
bool visited[101][101];

struct Cheeze
{
	int y, x;
};
queue<Cheeze> q;

int groupCount[101] = { 0, };

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool isInside(int ny, int nx)
{
	return ny >= 0 && nx >= 0 && ny < N && nx < N;
}

void bfs()
{
	while (!q.empty())
	{
		Cheeze c = q.front();
		q.pop();
		visited[c.y][c.x] = true;

		for (int i = 0; i < 4; i++)
		{
			int ny = c.y + dy[i];
			int nx = c.x + dx[i];
			if (isInside(ny, nx) && !visited[ny][nx])
			{
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T ;
	
	vector<int> TcheezeGroup(T);
	int while_count=0;
	while (T--)
	{
		memset(groupCount, 0, sizeof(groupCount));

		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> graph[i][j];

		for (int i = 0; i < 101; i++)
		{
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					if (graph[j][k] <= i)
						visited[j][k] = true;

			for(int j=0; j<N; j++)
				for( int k=0; k<N; k++)
					if (visited[j][k] == false)
					{
						groupCount[i]++;
						q.push({ j,k });
						bfs();
					}
			memset(visited, 0, sizeof(visited));
			//cout << i << ","<< groupCount[i] << endl;
		}

		int bestCount = 0;
		for (int i = 0; i < 101; i++)
			if (bestCount < groupCount[i])
				bestCount = groupCount[i];

		TcheezeGroup[while_count] = bestCount;
		while_count++ ;
	}

	for (int i = 0; i < TcheezeGroup.size(); i++)
		cout << "#" << i+1 << " " << TcheezeGroup[i] << "\n";

	return 0;
}