#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

#define MAX_S 51
#define endl "\n"

int N, M;
char graph[MAX_S][MAX_S];
bool visited[MAX_S][MAX_S], find_X[MAX_S][MAX_S];
struct Location
{
	int y, x;
};
queue<Location> q;
Location S, E;

struct X
{
	int y, x;
	int dist;
	friend bool operator < (const X &x1,const  X &x2)
	{
		return x1.dist < x2.dist;
	}
};
vector<X> X_vec;
priority_queue<X> X_seq;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool isInside(int ny, int nx)
{
	return ny >= 0 && nx >= 0 && ny < N && nx < M;
}

void bfs()
{
	int cnt=0;
	while (!q.empty())
	{
		int q_size = q.size();
		while (q_size--)
		{
			int y = q.front().y;
			int x = q.front().x;
			q.pop();

			if (find_X[y][x] == true)
			{
				X_vec.push_back({ y,x,cnt });
			}

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (isInside(ny, nx) && visited[ny][nx] == false)
				{
					visited[ny][nx] = true;
					q.push({ ny, nx });
				}
			}
		}
		cnt++;
	}
}

void solve()
{
	// bfs로 각 S와X의 거리 재기
	visited[S.y][S.x] = true;
	q.push(S);
	bfs();
	memset(visited, 0, sizeof(visited));

	// bfs로 각 E와X의 거리 재기
	visited[E.y][E.x] = true;
	q.push(E);
	bfs();
	memset(visited, 0, sizeof(visited));
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
			graph[i][j] = s[j];
			if (graph[i][j] == 'S')
				S = { i,j };
			if (graph[i][j] == 'E')
				E = { i,j };
			if (graph[i][j] == 'X')
				find_X[i][j] = true;
				//X_vec.push_back({ i,j,0 });
			if (graph[i][j] == '#')
				visited[i][j] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

}