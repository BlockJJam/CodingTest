#include <iostream>
#include <algorithm>
using namespace std;

#define endl "\n"
#define MAX_S 301


int N, M, R, Rotation_Pos;

int graph[MAX_S][MAX_S];
int C_graph[MAX_S][MAX_S];
bool visited[MAX_S][MAX_S];

void dfs(int y, int x, int dir, int r, int Range, int Orig)
{
	//r == R, c_graph�� Orig�� �ְ�, return
	if (r == R)
	{
		C_graph[y][x] = Orig;
		return;
	}
	//���⿡ ���� ������������ dfs�� �����ϴٰ� ���� �����ϸ� if������ ���� ��ȯ
	if (dir == 0)
	{
		if (x + 1 < M - Range)
			dfs(y, x + 1, dir, r + 1, Range, Orig);
		else
			dfs(y - 1, x, 3, r + 1, Range, Orig);
	}
	else if (dir == 1)
	{
		if (x - 1 >= Range)
			dfs(y, x - 1, dir, r + 1, Range, Orig);
		else
			dfs(y + 1, x, 2, r + 1, Range, Orig);
	}
	else if (dir == 2)
	{
		if (y + 1 < N - Range)
			dfs(y + 1, x, dir, r + 1, Range, Orig);
		else
			dfs(y, x + 1, 0, r + 1, Range, Orig);
	}
	else
	{
		if (y - 1 >= Range)
			dfs(y - 1, x, dir, r + 1, Range, Orig);
		else
			dfs(y, x - 1, 1, r + 1, Range, Orig);
	}
}

void solve()
{
	// �� ���� �������� �ϸ�, �� ������ dfs()�� ���� �湮ó���� �Ѵ�
	// �� 4���� �������� ����
	if (N > M) Rotation_Pos = M / 2;
	else Rotation_Pos = N / 2;

	for (int RP = 0; RP <= Rotation_Pos; RP++)
	{
		int x = RP;
		int y = RP;
		// ��-��-��-�� ������
		// ��
		for (int i = y; i < N - RP; i++)
		{
			if (visited[i][x] == false)
			{
				dfs(i, x, 2, 0, RP, graph[i][x]);
				visited[i][x] = true;
			}
		}
		// ��
		for (int i = x; i < M - RP; i++)
		{
			if (visited[N - RP - 1][i] == false)
			{
				dfs(N - RP - 1, i, 0, 0, RP, graph[N - RP - 1][i]);
				visited[N - RP - 1][i] = true;
			}
		}
		// ��
		for (int i = N - RP - 1; i >= RP; i--)
		{
			if (visited[i][M - RP - 1] == false)
			{
				dfs(i, M - RP - 1, 3, 0, RP, graph[i][M - RP - 1]);
				visited[i][M - RP - 1] = true;
			}
		}
		// ��
		for (int i = M - RP - 1; i >= RP; i--)
		{
			if (visited[y][i] == false)
			{
				dfs(y, i, 1, 0, RP, graph[y][i]);
				visited[y][i] = true;
			}
		}
	}
	//�� �ڸ��� ã���� C_grpah ���
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << C_graph[i][j] << " " ;
		cout << endl;
	}

}

void input()
{
	cin >> N >> M >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> graph[i][j];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}
