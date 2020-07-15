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

bool graph[101][101][2];

bool isBuild(int y, int x, int a, int n);

bool isUnBuild(int y, int x, int a, int n)
{
	if (a == 0)
	{
		// 기둥 해제
		graph[y][x][a] = false;

		// 위 기둥, 해당 보, 왼쪽 보 검사
		if (y + 1 < n)
		{
			if (graph[y + 1][x][0] == true)
				if (!isBuild(y + 1, x, 0, n))
				{
					graph[y][x][a] = true;
					return false;
				}
		}
		
		if (y + 1 < n && x - 1 >= 0)
		{
			if (graph[y + 1][x - 1][1] == true)
				if (!isBuild(y + 1, x - 1, 1, n))
				{
					graph[y][x][a] = true;
					return false;
				}
		}
		
		if (y + 1 < n)
		{
			if (graph[y + 1][x][1] == true)
				if (!isBuild(y + 1, x, 1, n))
				{
					graph[y][x][a] = true;
					return false;
				}
		}
		
		graph[y][x][a] = true;
		return true;
		
	}
	else
	{
		// 보 해제
		graph[y][x][a] = false;

		// 해당 x, x+1 기둥, x-1 ,x+1 보 지어지는지 검사
		if (x - 1 >= 0)
		{
			if (graph[y][x - 1][1] == true)
				if (!isBuild(y, x - 1, 1, n))
				{
					graph[y][x][a] = true;
					return false;
				}
		}
		
		if (x + 1 < n)
		{
			if (graph[y][x + 1][1] == true)
				if (!isBuild(y, x + 1, 1, n))
				{
					graph[y][x][a] = true;
					return false;
				}
		}
		
		if (x + 1 < n)
		{
			if (graph[y][x + 1][0] == true)
				if (!isBuild(y, x + 1, 0, n))
				{
					graph[y][x][a] = true;
					return false;
				}
		}
		
		
		if (graph[y][x][0] == true)
			if (!isBuild(y, x, 0, n))
			{
				graph[y][x][a] = true;
				return false;
			}

		graph[y][x][a] = true;
		return true;
	}
	
}

bool isBuild(int y, int x, int a, int n)
{
	if (a == 0)
	{
		// 바닥 or 보의 왼쪽 혹은 오른쪽 끝 위에 or 밑에 기둥이 있거나
		if (y == 0)
			return true;
		else if (y == n - 1)
			return false;
		else if (x == 0)
			return graph[y][x][1] == true || graph[y - 1][x][0] == true;
		else if (x == n - 1)
			return graph[y][x - 1][1] == true || graph[y - 1][x][0] == true;
		else 
			return  graph[y][x - 1][1] == true || graph[y][x][1] == true || graph[y - 1][x][0] == true;
	}
	else
	{
		if (y == 0)
			return false;
		else if (x == 0)
			return graph[y - 1][x][0] == true || graph[y - 1][x + 1][0] == true;
		else if (x == n - 1)
			return false;
		else
			return graph[y - 1][x][0] == true || graph[y - 1][x + 1][0] == true || (graph[y][x - 1][1] == true && graph[y][x + 1][1] == true);
	}
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	n = n + 1;
	FOR(i, 0, build_frame.size())
	{
		int x = build_frame[i][0];
		int y = build_frame[i][1];
		int a = build_frame[i][2];
		int b = build_frame[i][3];

		if (b == 1)
		{
			//설치과정
			if (isBuild(y, x, a, n) == true)
			{
				//설치가능
				graph[y][x][a] = true;
			}
			else
			{
				//설치불가능
				continue;
			}
		}
		else
		{
			//해체과정
			if (isUnBuild(y, x, a, n) == true)
			{
				//해체가능
				graph[y][x][a] = false;
			}
			else
			{
				//해체 불가능
				continue;
			}
		}
	}

	// build가 잘 됐는지 x기준 -> y -> 기둥 -> 보 기준으로 answer에 넣는다
	FOR(j, 0, n)
	{
		FOR(i, 0, n)
		{
			if (graph[i][j][0] == true)
				answer.push_back({ j,i,0 });
			if (graph[i][j][1] == true)
				answer.push_back({ j,i,1 });
		}
	}

	FOR(i, 0, answer.size())
	{
		FOR(j, 0, answer[i].size())
		{
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}
	return answer;
}

int main()
{
	vector<vector<int>> b = { {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} };
	solution(5, b);
}
/*
	{ {1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1} }
	{{0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1}}
*/