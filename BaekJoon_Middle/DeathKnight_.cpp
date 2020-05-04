#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <bitset>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;

#define FOR(i,n) for(int i=0; i<(n); i++)

int N;
const int MAX = 201;
int graph[MAX][MAX];
bool visited[MAX][MAX];
int move_count = 0;
struct Point
{
	int y;
	int x;
};
queue<Point> q;
Point finish, start;

int dy[6] = { -1, 1, -2, 2, -1 ,1 };
int dx[6] = { -2, -2, 0, 0, 2 ,2 };

bool isInside(int ny, int nx)
{
	return ny >= 0 && nx >= 0 && ny < N && nx < N;
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	cin >> start.x >> start.y >> finish.x >> finish.y;
}

void bfs()
{
	while (true)
	{
		int q_size = q.size();

		if (q_size == 0)
		{
			move_count = -1;
			return;
		}

		while (q_size--)
		{
			int y = q.front().y;
			int x = q.front().x;
			//cout << x << " " << y << endl;
			q.pop();

			if (finish.y == y && finish.x == x)
				return;

			FOR(i, 6)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (isInside(ny, nx) && visited[ny][nx] == false)
				{
					visited[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}
		move_count++;
	}
}

void solve()
{
	q.push(start);
	bfs();

	cout << move_count << endl;
}

int main()
{
	input();
	solve();

	return 0;
}