// 자물쇠와 열쇠

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

int N, M, hole_count=0;
int graph[60][60], key_graph[60][60];
bool visited[60][60];
bool isOpen=false;
vector<vector<int>> c_key;

vector<pair<int,int>> hole;
vector<pair<int, int>> pick;


// 좌우상하 이동
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

bool isInsideGraph(int by, int bx)
{
	return by >= 0 && bx >= 0 && by < N + M - 1 && bx < N + M - 1;
}

bool isInsideLock(int ny, int nx)
{
	return ny >= N && nx >= N && ny < N * 2 && nx < N * 2;
}


// 회전 이동
void rotate(int by, int bx)
{
	vector<vector<int>>temp_vec(M, vector<int>(M, 0));
	
	
	FOR(i, 0, M)
	{
		FOR(j, 0, M)
		{
			//cout << i << j << endl;
			temp_vec[i][j] = c_key[M - j - 1][i];
			if (temp_vec[i][j] == 1)
				pick.push_back({ by + i, bx + j });
		}
	}
	c_key = temp_vec;
}


// BFS
void bfs(int by, int bx, int ey, int ex)
{
	if (visited[by][bx] == true || isOpen == true)
		return ;
	if (by + M == ey && bx + M == ex)
		return ;
	cout << " begin: " << by << "," << bx << endl;
	FOR(i, 0, 4)
	{
		//rotate를 돌리고
		rotate(by, bx);
		//pick의 좌표가 1일때 graph의 해당 좌표가 모두 0이면 return true;
		int pick_count = 0;
		FOR(j, 0, pick.size())
		{
			int y = pick[j].first;
			int x = pick[j].second;
			
			if (isInsideLock(y, x) == true)
			{

				if (graph[y][x] == 1)
				{
					pick_count = 0;
					break;
				}
				else
				{
					//cout << j << " pick: " << y << "," << x << endl;
					pick_count++;
				}
			}
		}

		pick.clear();
		// 문이 열리는지 확인
		if (pick_count == hole_count)
		{
			//cout <<"!!!!!!!!!" << endl;
			isOpen = true;
			return ;
		}
	}
	visited[by][bx] = true;
	// 오른쪽으로 이동
	if (bx + M < N * 3)
		bfs(by, bx + 1, ey, ex);
	// 아래로 이동
	if (by + M < N * 3)
		bfs(by + 1, bx, ey, ex);
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;

	N = lock.size();
	M = key.size();
	FOR(i, 0, N)
	{
		FOR(j, 0, N)
		{
			graph[N + i][N + j] = lock[i][j];
			if (graph[N + i][N + j] == 0)
			{
				hole.push_back({ N + i,N + j });
				hole_count++;
			}
		}
	}

	FOR(i, 0, hole.size())
		cout << hole[i].first << "," << hole[i].second << endl;

	c_key = key;
	int bx = 0, by = 0; 
	int ex = N * 3, ey = N * 3;

	bfs(by, bx, ey, ex);
	answer = isOpen;

	return answer;
}

int main()
{
	vector<vector<int>> key = { {0, 0, 0},{1, 0, 0},{0, 1, 1} };
	vector < vector<int>> lock = { {1, 1, 1},{1, 1, 0},{1, 0, 1} };
	cout << solution(key, lock) << endl;
}