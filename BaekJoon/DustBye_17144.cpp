#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define endl "\n"
#define MAX_S 51

int N, M ,T;
int graph[MAX_S][MAX_S], c_graph[MAX_S][MAX_S];
bool visited[MAX_S][MAX_S];
int result;

struct Location
{
	int y, x;
};
vector<Location> wind_M;


int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool isInside(int ny, int nx)
{
	return ny >= 0 && nx >= 0 && ny < N && nx < M;
}

void spread(int y, int x)
{
	int spread_count = 0;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (isInside(ny, nx) && graph[ny][nx] != -1 )
		{
			++spread_count;
			c_graph[ny][nx] += ( graph[y][x] / 5 );
		}
	}
	graph[y][x] = graph[y][x] - (graph[y][x] / 5 * spread_count);
}

bool rwind_finish = false;
void rwind(int y, int x, int dir)
{
	if (rwind_finish == true) return;
	// 동 서 남 북
	if (dir == 0)
	{
		if ( x + 1 < M )
		{
			c_graph[y][x + 1] = graph[y][x];
			rwind(y, x + 1, 0);
		}
		else
		{
			c_graph[y - 1][x] = graph[y][x];
			rwind(y - 1, x, 3);
		}
	}
	else if (dir == 1)
	{
		if (x - 1 >= 0)
		{
			c_graph[y][x - 1] = graph[y][x];
			rwind(y, x - 1, 1);
		}
		else
		{
			c_graph[y + 1][x] = graph[y][x];
			rwind(y + 1, x, 2);
		}
	}
	else if (dir == 2)
	{
		if (graph[y + 1][x] == -1)
		{
			rwind_finish = true;
			return;
		}
		if (y + 1 <= wind_M[0].y)
		{
			c_graph[y + 1][x] = graph[y][x];
			rwind(y + 1, x, 2);
		}
	}
	else
	{
		if (y - 1 >= 0)
		{
			c_graph[y - 1][x] = graph[y][x];
			rwind(y - 1, x, 3);
		}
		else
		{
			c_graph[y][x - 1] = graph[y][x];
			rwind(y, x - 1, 1);
		}
	}
}

bool wind_finish = false;
void wind(int y, int x, int dir)
{
	if (wind_finish == true) return;
	// 동 서 남 북
	if (dir == 0)
	{
		if (x + 1 < M)
		{
			c_graph[y][x + 1] = graph[y][x];
			wind(y, x + 1, 0);
		}
		else
		{
			c_graph[y + 1][x] = graph[y][x];
			wind(y + 1, x, 2);
		}
	}
	else if (dir == 1)
	{
		if (x - 1 >= 0)
		{
			c_graph[y][x - 1] = graph[y][x];
			wind(y, x - 1, 1);
		}
		else
		{
			c_graph[y - 1][x] = graph[y][x];
			wind(y - 1, x, 3);
		}
	}
	else if (dir == 2)
	{
		if (y + 1 < N)
		{
			c_graph[y + 1][x] = graph[y][x];
			wind(y + 1, x, 2);
		}
		else
		{
			c_graph[y][x - 1] = graph[y][x];
			wind(y, x - 1, 1);
		}
	}
	else
	{
		if (graph[y - 1][x] == -1)
		{
			wind_finish = true;
			return;
		}
		if (y - 1 >= wind_M[1].y)
		{
			c_graph[y - 1][x] = graph[y][x];
			wind(y - 1, x, 3);
		}
	}
}


void solve()
{
	// 확산 시키기
	fill(&c_graph[0][0], &c_graph[MAX_S - 1][MAX_S], 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] != 0 && graph[i][j] != -1)
				spread(i, j);
		}
	}

	// 확산한 그래프를 원래그래프에 붙이기
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (c_graph[i][j] != 0 && c_graph[i][j] != -1)
			{
				graph[i][j] += c_graph[i][j];
				c_graph[i][j] = -2;
			}
		}



	fill(&c_graph[0][0], &c_graph[MAX_S - 1][MAX_S], -2);
	//공기 청정기에서 바람밀기
	for (int i = 0; i < wind_M.size(); i++)
	{

		int y_start = wind_M[i].y;
		int x_start = wind_M[i].x +1;
		c_graph[y_start][x_start] = 0;
		if (i == 0)
			rwind(y_start, x_start, 0);
		else
			wind(y_start, x_start, 0);
	}
	rwind_finish = false; wind_finish = false;
	

	// c_graph 값을 graph 값으로 옮기기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (c_graph[i][j] != -2)
			{
				graph[i][j] = c_graph[i][j];
				c_graph[i][j] = -2;
			}
		}
	}
}

void input()
{
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == -1)
				wind_M.push_back({ i,j });
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	for (int i = 0; i < T; i++)
	{
		solve();
	}

	for(int i=0; i<N; i++)
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] != -1)
				result += graph[i][j];
		}
	cout << result <<endl;
}
/*

	//출력기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << graph[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;
*/