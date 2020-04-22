#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int graph[101][101];
bool cleanState[101][101];

struct Robot
{
	int y, x;
	int d;	// 0 : 合率 1: 悼率 2: 巢率 3: 巢率
};
Robot r;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool isInside(int ny, int nx)
{
	return ny >= 0 && nx >= 0 && ny < N && nx < M;
}

int turnLeft(int d)
{
	if (d == 0) return 3;
	else if (d == 1) return 0;
	else if(d == 2) return 1;
	else if (d == 3) return 2;
}

void RobotSearch(int y, int x, int d)
{
	cleanState[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int ny = r.y + dy[(4 - d + i) % 4];
		int nx = r.x + dx[(4 - d + i) % 4];
		r.d = turnLeft(r.d);
		if (isInside(ny,nx) && cleanState[ny][nx] == false)
		{
			r.x = nx;
			r.y = ny;
			//cout << r.y << "," << r.x << endl;
			RobotSearch(r.y, r.x, r.d);
			break;
		}
	}
	switch (r.d)
	{
	case 0:
		//cout << " N " << endl;
		if (!isInside(r.y + 1, r.x) || graph[r.y + 1][r.x] == 1)
			return;

		r.y = r.y + 1;
		RobotSearch(r.y, r.x, r.d);
		break;

	case 1:
		//cout << "E" << endl;
		if (!isInside(r.y, r.x - 1) || graph[r.y][r.x - 1] == 1)
			return;

		r.x = r.x - 1;
		RobotSearch(r.y, r.x, r.d);
		break;
	case 2:
		//cout << " S " << endl;
		if (!isInside(r.y - 1, r.x) || graph[r.y - 1][r.x] == 1)
			return;

		r.y = r.y - 1;
		RobotSearch(r.y, r.x, r.d);
		break;

	case 3:
		//cout << " W " << endl;
		if (!isInside(r.y, r.x + 1) || graph[r.y][r.x + 1] == 1)
			return;

		r.x = r.x + 1;
		RobotSearch(r.y, r.x, r.d);
		break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cnt = 0;

	memset(graph, 0, sizeof(graph));
	memset(cleanState, 0, sizeof(cleanState));

	cin >> N >> M;
	cin >> r.y >> r.x >> r.d;


	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 1)
				cleanState[i][j] = true;
		}

	RobotSearch(r.y, r.x, r.d);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (cleanState[i][j] == true && graph[i][j] ==0)
				cnt++;


	cout << cnt ;

	return 0;
}
