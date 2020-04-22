#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

vector<string> graph(6);
vector<vector<bool>> visited(6, vector<bool>(12, false));
vector<vector<bool>> isBoom(6, vector<bool>(12, false));

int chainCount = 0;
int boomPuyoCount = 0;
bool chainStop = true;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

struct Puyo
{
	int x, y;
	char color;
};
queue<Puyo> q;

bool isInside(int nx, int ny)
{
	return 0 <= nx && 0 <= ny && nx < 6 && ny < 12;
}

void dfs(int x, int y, char color)
{
	Puyo p;
	p = { x,y,color };
	visited[x][y] = true;
	boomPuyoCount+=1;
	for (int i = 0; i < 4; i++)
	{
		int nx = p.x + dx[i];
		int ny = p.y + dy[i];
		if (isInside(nx, ny) && !visited[nx][ny] && graph[nx][ny] == p.color)
			dfs(nx, ny, graph[nx][ny]);
	}

	q.push({ x,y,color });
	
	/*
	if (boomPuyoCount >= 4)
	{
		isBoom[x][y] = true;
		chainStop = false;
	}
	*/
}

void boomPuyo()
{
	for (int i = 0; i < 6; ++i)
		for (int j = 11; j >= 0; --j)
			if (isBoom[i][j])
				graph[i][j] = '-';

	//for (int i = 0; i < 6; i++)
	//{
	//	for (int j = 0; j < 12; j++)
	//		cout << isBoom[i][j] << " ";
	//	cout << endl;
	//}

	for(int i=0; i<6; ++i)
		for(int j=0; j<12; ++j)
			if (graph[i][j] == '-')
			{
				graph[i].erase(find(graph[i].begin(), graph[i].end(), '-'));
				graph[i].insert(0, 1, '.');
			}

	//for (int i = 0; i < 6; i++)
	//	cout << graph[i] << endl;
	//cout << endl;
}

void puyoBoom()
{
	for (int i = 11;i>=0; i--)
		for (int j = 0; j < 6; j++)
		{
			if (graph[j][i] == '.'|| visited[j][i])
				continue;
			/*cout << j << "," << i << " " << endl;*/
			dfs(j, i, graph[j][i]);
			if (boomPuyoCount >= 4)
				while (!q.empty())
				{
					isBoom[q.front().x][q.front().y] = true;
					q.pop();
					chainStop = false;
				}
			else
				while (!q.empty())
					q.pop();
			boomPuyoCount = 0;
		}

	if(!chainStop)
		boomPuyo();
	else
		return;

	chainCount++;
	chainStop = true;

	visited = vector<vector<bool>>(6, vector<bool>(12, false));
	isBoom = vector<vector<bool>>(6, vector<bool>(12, false));
	puyoBoom();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 6; i++)
		graph[i] = "";

	for (int i = 0; i < 12; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < 6; ++j)
			graph[j] += s[j];
	}

	//for (int i = 0; i < 6; i++)
	//	cout << graph[i] << endl;
	//cout << endl;

	puyoBoom();
	cout << chainCount;

	return 0;
}
/* 다른 C++ 풀이
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>

#define endl "\n"
using namespace std;

char MAP[12][6];
bool Visit[12][6];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int Boom_Cnt = 0;
int Temp_Cnt = 0;

vector<pair<int, int>> Boom_Tmp, Boom_Vec;

void Input()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> MAP[i][j];
		}
	}
}

void DFS(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
		if (MAP[nx][ny] == '.') continue;
		if (Visit[nx][ny] == true) continue;
		if (MAP[x][y] != MAP[nx][ny]) continue;

		Temp_Cnt++;
		Visit[nx][ny] = true;
		Boom_Tmp.push_back(make_pair(nx, ny));
		DFS(nx, ny);
	}
}

void Solution()
{
	bool Flag;
	int Answer = 0;
	while (1)
	{
		Flag = false;
		memset(Visit, false, sizeof(Visit));
		Boom_Vec.clear();

		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (MAP[i][j] != '.' && Visit[i][j] == false)
				{
					Temp_Cnt = 1;
					Boom_Tmp.push_back(make_pair(i, j));
					Visit[i][j] = true;
					DFS(i, j);

					if (Temp_Cnt >= 4)
					{
						Flag = true;    // 뿌요가 터졌다고 표시.
						for (int i = 0; i < Boom_Tmp.size(); i++)
						{
							Boom_Vec.push_back(Boom_Tmp[i]);    // 해당 좌표들 옮겨주기
						}
					}
					Boom_Tmp.clear();
				}
			}
		}

		for (int i = 0; i < Boom_Vec.size(); i++)
		{
			int x = Boom_Vec[i].first;
			int y = Boom_Vec[i].second;

			MAP[x][y] = '.';
		}

		for (int i = 10; i >= 0; i--)
		{
			for (int j = 0; j < 6; j++)
			{
				if (MAP[i][j] == '.') continue;
				int Tmp = i;

				while (1)
				{
					if (Tmp == 11 || MAP[Tmp + 1][j] != '.') break;

					MAP[Tmp + 1][j] = MAP[Tmp][j];
					MAP[Tmp][j] = '.';
					Tmp++;
				}
			}
		}
		if (Flag == true) Answer++;
		else break;
	}
	cout << Answer << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("Input.txt", "r", stdin);
	Solve();

	return 0;
}

*/