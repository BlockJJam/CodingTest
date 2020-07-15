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

int N, M;
char graph[21][21];
int answer = -1;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

bool isInside(int ny, int nx)
{
	return ny >= 0 && nx >= 0 && ny < N && nx < M;
}

int isWall(int A_ny, int A_nx, int B_ny, int B_nx)
{
	if (graph[A_ny][A_nx] == '#' && graph[B_ny][B_nx] == '#')
		return 3;
	else if (graph[B_ny][B_nx] == '#')
		return 2;
	else if (graph[A_ny][A_nx] == '#')
		return 1;
	else
		return 0;
}

void moveCoin(int A_y, int A_x, int B_y, int B_x, int step)
{
	if (step > 10)
		return;

	FOR(i, 0, 4)
	{
		int A_ny = A_y + dy[i]; int A_nx = A_x + dx[i];
		int B_ny = B_y + dy[i]; int B_nx = B_x + dx[i];
		int next_step = step + 1;
		
		// 한가지 동전만 떨어질 수 있는 경우
		if (!isInside(A_ny, A_nx) && isInside(B_ny, B_nx))
		{
			if (next_step == 11) return;
			//cout << "1" << endl;
			if (answer == -1)
				answer = next_step;
			else if (answer > next_step)
				answer = next_step;

			//cout << answer << endl;
			return;
		}
		else if (isInside(A_ny, A_nx) && !isInside(B_ny, B_nx))
		{
			if (next_step == 11) return;
			//cout << "1" << endl;
			if (answer == -1)
				answer = next_step;
			else if (answer > next_step)
				answer = next_step;

			//cout << answer << endl;
			return;
		}

		//cout << "2" << endl;
		// 이동을 할 수 없는 경우 : 둘 다 벽에 막히거나, 둘 다 그래프에서 떨어지는 경우
		if (!isInside(A_ny, A_nx) && !isInside(B_ny, B_nx))
			continue;
		if (isWall(A_ny, A_nx, B_ny, B_nx) == 3)
			continue;

		//cout << "3" << endl;
		// 한가지 이동이 가능한 경우( 둘 중 하나만 벽을 만나는 경우 )
		if (isWall(A_ny, A_nx, B_ny, B_nx) == 1)
			moveCoin(A_y, A_x, B_ny, B_nx, next_step);
		else if (isWall(A_ny, A_nx, B_ny, B_nx) == 2)
			moveCoin(A_ny, A_nx, B_y, B_x, next_step);

		//cout << "4" << endl;
		// 두 동전이 모두 이동가능한 경우
		if (isWall(A_ny, A_nx, B_ny, B_nx) == 0 && isInside(A_ny, A_nx) && isInside(B_ny, B_nx))
			moveCoin(A_ny, A_nx, B_ny, B_nx, next_step);

	}
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	int A_y, A_x;
	int B_y, B_x;
	bool AorB=false;
	FOR(i, 0, N)
	{
		FOR(j, 0, M)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 'o' && AorB == false)
			{
				A_y = i;
				A_x = j;
				AorB = true;
			}
			if (graph[i][j] == 'o' && AorB == true)
			{
				B_y = i;
				B_x = j;
				//AorB = false;
			}
		}
	}
	//if(AorB== false)
	if (N == 1 && M == 1)
		answer = -1;
	else
		moveCoin(A_y, A_x, B_y, B_x, 0);
	
	cout << answer;
}

int main()
{
	input();

	return 0;

}