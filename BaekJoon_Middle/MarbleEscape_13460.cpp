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

int N, M, answer = -1;
char graph[11][11];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };


int isWall(int Ay, int Ax, int By, int Bx)
{
	if (graph[Ay][Ax] == '#' && graph[By][Bx] == '#')
		return 3;
	else if (graph[Ay][Ax] == '#')
		return 2;
	else if (graph[By][Bx] == '#')
		return 1;
	else
		return 0;
}

bool isSameLoc(int Ay, int Ax, int By, int Bx)
{
	if (Ay == By && Ax == Bx)
		return true;
	return false;
}

bool isBlueInHole(int By, int Bx)
{
	return graph[By][Bx] == 'O' ? true : false;
}

void moveBall(int Ay, int Ax, int By, int Bx, int step, bool red)
{
	bool RedCheck = red;

	if(step == 11)
		return;
	if (answer != -1)
		if (step == answer)
			return;

	//cout << Ay << "," << Ax << " " << By << "," << Bx <<" " <<  step << " " << red << endl;
	if (RedCheck == true)
	{
		//cout << step << endl;
		if (answer == -1)
			answer = step;
		else
			answer = answer > step ? step : answer;

		return;
	}

	FOR(i, 0, 4)
	{
		int A_ny = Ay;
		int A_nx = Ax;
		int B_ny = By;
		int B_nx = Bx;

		while (true)
		{
			// 파란 공 탈출 가능한 상황
			if (isBlueInHole(B_ny + dy[i], B_nx + dx[i]))
			{
				A_ny = Ay;
				A_nx = Ax;
				B_ny = By;
				B_nx = Bx;
				break;
			}
			// 빨간 공 탈출 가능한 상황
			if (graph[A_ny][A_nx] == 'O')
			{
				RedCheck = true;
			}
			// 움직일 수 없는 상황
			if (isWall(A_ny + dy[i], A_nx + dx[i], B_ny + dy[i], B_nx + dx[i]) == 3)
				break;

			if (isWall(A_ny + dy[i], A_nx + dx[i], B_ny + dy[i], B_nx + dx[i]) == 0)
			{
				// A,B
				A_ny = A_ny + dy[i];
				A_nx = A_nx + dx[i];
				B_ny = B_ny + dy[i];
				B_nx = B_nx + dx[i];
			}
			else if (isWall(A_ny + dy[i], A_nx + dx[i], B_ny + dy[i], B_nx + dx[i]) == 1)
			{
				if (isSameLoc(A_ny + dy[i], A_nx + dx[i], B_ny, B_nx))
					break;
				// A
				A_ny = A_ny + dy[i];
				A_nx = A_nx + dx[i];
			}
			else if (isWall(A_ny + dy[i], A_nx + dx[i], B_ny + dy[i], B_nx + dx[i]) == 2)
			{
				if (isSameLoc(A_ny, A_nx, B_ny + dy[i], B_nx + dx[i]))
					break;
				// B
				B_ny = B_ny + dy[i];
				B_nx = B_nx + dx[i];
			}
		}

		if (Ay == A_ny && Ax == A_nx && By == B_ny && Bx == B_nx)
		{
			RedCheck = false;
			continue;
		}
		else
			moveBall(A_ny, A_nx, B_ny, B_nx, step + 1, RedCheck);
	}
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int Ay, Ax;
	int By, Bx;

	cin >> N >> M;
	string str;

	FOR(i, 0, N)
	{
		cin >> str;
		FOR(j, 0, M)
		{
			graph[i][j] = str[j];
			if (graph[i][j] == 'R')
			{
				Ay = i;
				Ax = j;
			}
			if (graph[i][j] == 'B')
			{
				By = i;
				Bx = j;
			}
		}
	}

	moveBall(Ay, Ax, By, Bx, 0, false);
}

int main()
{
	input();

	cout << answer << endl;
	return 0;
}