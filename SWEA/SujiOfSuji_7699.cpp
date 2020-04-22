#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int T, R, C;
char graph[21][21];
bool visited[26] = { 0 ,};

struct Treasure
{
	int y, x;
	char t;
};
queue<Treasure> q;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool isInside(int ny, int nx)
{
	return ny >= 0 && nx >= 0 && ny < R && nx < C;
}

int ans_bfs_dfs = 0;
void dfs(int y, int x, int k)
{

	ans_bfs_dfs = ans_bfs_dfs < k ? k : ans_bfs_dfs;
	if (ans_bfs_dfs == 26)
		return;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		int visit = graph[ny][nx] - 'A';
		/*
		for (int i = 0; i < 26; i++)
			cout << visited[i] << " ";
		cout << endl;*/

		if (isInside(ny, nx) && !visited[visit])
		{
			visited[visit] = true;
			dfs(ny, nx, k+1);
			visited[visit] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string bfs_s, dfs_s;

	cin >> T;
	vector<int> ans(T);
	for (int i = 0; i < T; i++)
	{
		cin >> R >> C;
		for (int j = 0; j < R; j++)
		{
			string s;
			cin >> s;
			for (int k = 0; k < C; k++)
				graph[j][k] = s[k];
		}
		int visit = graph[0][0] - 'A';
		visited[visit] = true;
		dfs(0,0,1);
		ans[i] = ans_bfs_dfs;

		ans_bfs_dfs = 0;
		fill(&visited[0], &visited[0] + sizeof(visited), false);
	}

	for (int i = 0; i < T; i++)
	{
		cout << "#" << i + 1 << " " << ans[i] << "\n";
	}
}