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

int graph[103][103];
bool visited[103][103][2];
int N, total_count = 0;

struct Point
{
	int id, y, x;
};

queue<pair<Point, Point>> q; // m1 m2를 위치 queue

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

bool isInside(int ny, int nx)
{
	return ny >= 1 && nx >= 1 && ny < N+1 && nx < N+1;
}

bool isRotate(Point &m1, Point &m2)
{
	// m1이 왼쪽
	if (m1.x == m2.x - 1)
	{
		//cout << "왼" << endl;
		return graph[m1.y - 1][m1.x + 1] == 0 && visited[m1.y - 1][m1.x][m2.id] == false;
	}
	else if (m1.y == m2.y + 1)
	{
		// m1이 아래쪽
		//cout << "아" << endl;
		return graph[m1.y - 1][m1.x - 1] == 0 && visited[m1.y][m1.x - 1][m2.id] == false;
	}
	else if (m1.x == m2.x + 1)
	{
		// m1이 오른족
		//cout << "오" << endl;
		return graph[m1.y + 1][m1.x - 1] == 0 && visited[m1.y + 1][m1.x][m2.id] == false;
	}
	else
	{
		// m2이 위쪽
		//cout << "위" << endl;
		return graph[m1.y + 1][m1.x + 1] == 0 && visited[m1.y][m1.x + 1][m2.id] == false;
	}
}

void rotate(Point& m1, Point&m2)
{
	// m1이 왼쪽, m1기준
	if (m1.x == m2.x - 1)
	{
		m2.y -= 1;
		m2.x -= 1;
	}
	else if (m1.y == m2.y + 1)
	{
		// m1이 아래쪽
		m2.y += 1;
		m2.x -= 1;
	}
	else if (m1.x == m2.x + 1)
	{
		// m1이 오른족
		m2.y += 1;
		m2.x += 1;
	}
	else
	{
		// m1이 위쪽
		m2.y -= 1;
		m2.x += 1;
	}
}

void bfs()
{
	while (!q.empty())
	{
		int qs = q.size();
		while (qs--)
		{
			//cout << q.size() << endl;
			Point m1 = q.front().first;
			Point m2 = q.front().second;
			q.pop();
			if ((m1.y == N && m1.x == N) || (m2.y == N && m2.x == N))
			{
				//cout << "!" << endl;
				return;
			}
			//cout << m1.id << m1.y << m1.x << " " << m2.id << m2.y << m2.x <<endl;
			FOR(i, 0, 5)
			{
				int ny1, nx1, id1;
				int ny2, nx2, id2;
				if (i < 4)
				{
					// 우하좌상
					ny1 = m1.y + dy[i];
					nx1 = m1.x + dx[i];
					id1 = m1.id;

					ny2 = m2.y + dy[i];
					nx2 = m2.x + dx[i];
					id2 = m2.id;
					//cout << m1.id << m1.y << m1.x << " " << m2.id << m2.y << m2.x;

					if (isInside(ny1, nx1) && isInside(ny2, nx2) && (!visited[ny1][nx1][id1] || !visited[ny2][nx2][id2]) )
					{
						visited[ny1][nx1][id1] = true; visited[ny2][nx2][id2] = true;
						q.push({ { id1,ny1,nx1 }, { id2,ny2,nx2 } });
						//cout << m1.id << m1.y << m1.x << " " << m2.id << m2.y << m2.x;
					}
				}
				if (i == 4)
				{
					// m1 기준 회전
					Point nm1 =m1, nm2= m2;
					//cout << m1.id << m1.y << m1.x << " " << m2.id << m2.y << m2.x <<endl;
					if (isRotate(nm1, nm2))
					{
						//cout << m1.id << m1.y << m1.x << " " << m2.id << m2.y << m2.x;
						rotate(nm1, nm2);
						visited[nm1.y][nm1.x][nm1.id] = true; visited[nm2.y][nm2.x][nm2.id] = true;

						q.push({ nm1, nm2 });
					}
					//cout << m1.id << m1.y << m1.x << " " << m2.id << m2.y << m2.x;
					// m2 기준 회전
					nm1 = m2, nm2 = m1;
					if (isRotate(nm1, nm2))
					{
						//cout << m1.id << m1.y << m1.x << " " << m2.id << m2.y << m2.x;
						rotate(nm1, nm2);
						visited[nm1.y][nm1.x][nm1.id] = true; visited[nm2.y][nm2.x][nm2.id] = true;
						q.push({ nm1, nm2 });
					}
				}
			}
		}
		total_count++;
	}
	total_count = 0;
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	N = board.size();
	FOR(i, 0, 102)
		FOR(j, 0, 102)
		FOR(k, 0, 2)
		{
			visited[i][j][k] = true;
			graph[i][j] = 1;
		}

	FOR(i, 1, N + 1)
	{
		FOR(j, 1, N + 1)
		{
			graph[i][j] = board[i - 1][j - 1];
			if (graph[i][j] == 0)
			{
				visited[i][j][0] = false;
				visited[i][j][1] = false;
			}
		}
	}
	//FOR(i, 0, N + 2)
	//{
	//	FOR(j,0,N+2)
	//	{
	//		cout << graph[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	Point m1{ 0,1,1 };
	Point m2{ 1,1,2 };
	q.push({ m1, m2 });

	visited[m1.y][m1.x][0] = true;
	visited[m2.y][m2.x][1] = true;
	bfs();
	
	answer = total_count;
	cout <<"answer " <<answer;
	return answer;
}

int main()
{
	vector<vector<int>> b({ {0, 0, 0, 1, 1}, {0, 0, 0, 1, 0}, {0, 1, 0, 1, 1}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0} });
	solution(b);

	return 0;
}