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
using namespace std;

#define FOR(i,m,n) for(int i=(m); i<(n); i++)
#define endl "\n"

int N;
int graph[21][21];
bool visited[21][21];
int answer = 0;

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };
bool isInside(int ny, int nx)
{
	return ny >= 0 && nx >= 0 && ny < N && nx < N;
}

struct Shark
{
	int size ;
	int exp ;
	int y, x;
};
queue<Shark> q;

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	FOR(i, 0, N)
	{
		FOR(j, 0, N)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 9)
			{
				q.push({ 2,0,i,j });
				visited[i][j] = true;
				graph[i][j] = 0;
			}
		}
	}
}

void solve()
{
	int move = 0;
	while (!q.empty())
	{
		int q_size = q.size();
		
		while (q_size--)
		{
			int y = q.front().y, x = q.front().x, ss = q.front().size, se = q.front().exp;
			q.pop();

			FOR(i, 0, 4)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (isInside(ny, nx))
				{
					if (graph[ny][nx] != 0 && graph[ny][nx] < ss)
					{
						++se;
						if (ss == se)
						{
							++ss;
							se = 0;
						}
						while (!q.empty()) q.pop();
						q.push({ ss,se,ny,nx });
						q_size = 1;
						memset(&visited, 0, sizeof(visited));
					
						visited[ny][nx] = true;
						graph[ny][nx] = 0;
						
						answer += move+1;
						cout << ny << "," << nx << ", "<< answer<< endl;
						FOR(i, 0, N)
						{
							FOR(j, 0, N)
								cout << graph[i][j] << " ";
							cout << endl;
						}

						move = 0;
						break;
					}
					else if (visited[ny][nx] == false && graph[ny][nx] <= ss)
					{
						visited[ny][nx] = true;
						q.push({ ss, se, ny,nx });
					}
				}
			}
		}
		move++;
		//cout << move << endl;
	}
}

int main()
{
	input();
	solve();

	cout << answer;

	return 0;
}