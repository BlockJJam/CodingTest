#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_S 51
#define endl "\n"

int N, M, K;
int A_graph[MAX_S][MAX_S], C_graph[MAX_S][MAX_S], graph[MAX_S][MAX_S];
int A_min = 50000;

struct Spin
{
	int y, x, s;
};
vector<Spin> spin;
vector<Spin> seq;

void change(int y, int x, int y_start, int x_start, int y_end, int x_end, int dir, int Range, int Orig)
{
	//동 서 남 북
	if (dir == 0)
	{

		if (x + 1 <= x_end)
			C_graph[y][x + 1] = Orig;
		else
			C_graph[y + 1][x] = Orig;
	}
	else if (dir == 1)
	{
		if (x - 1 >= x_start )
			C_graph[y][x - 1] = Orig;
		else
			C_graph[y - 1][x] = Orig;
	}
	else if (dir == 2)
	{
		if (y + 1 <= y_end)
			C_graph[y + 1][x] = Orig;
		else
			C_graph[y][x - 1] = Orig;
	}
	else
	{
		if (y - 1 >= y_start )
			C_graph[y - 1][x] = Orig;
		else
			C_graph[y][x + 1] = Orig;
	}
}
void search(int n, int m)
{
	if (m == 0)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				A_graph[i][j] = graph[i][j];

		for (int i = 0; i < K; i++)
		{
			int R_P = seq[i].s;
			for (int RP = 0; RP < R_P; RP++)
			{
				int y		= seq[i].y - seq[i].s + RP - 1;
				int y_end	= seq[i].y + seq[i].s - RP - 1;
				int x		= seq[i].x - seq[i].s + RP - 1;
				int x_end	= seq[i].x + seq[i].s - RP - 1;

				//오 - 아- 왼 -위 순으로
				for (int j = x; j <= x_end ; j++)
					change(y, j, y, x, y_end, x_end, 0, RP, A_graph[y][j]);

				for (int j = y; j <= y_end ; j++)
					change(j, x_end, y, x, y_end, x_end, 2, RP, A_graph[j][x_end]);

				for (int j = x_end; j >= x; j--)
					change(y_end, j, y, x, y_end, x_end, 1, RP, A_graph[y_end][j]);

				for (int j = y_end; j >= y; j--)
					change(j, x, y, x, y_end, x_end, 3, RP, A_graph[j][x]);
			}
			// 옮긴 C_graph를 A_graph에 옮겨 A_min을 계산할 수 있게 한다
			for (int j = seq[i].y - seq[i].s-1; j < seq[i].y + seq[i].s; j++)
				for (int k = seq[i].x - seq[i].s - 1; k < seq[i].x + seq[i].s ; k++)
				{
					if (C_graph[j][k] == 0) continue;
					A_graph[j][k] = C_graph[j][k];
				}
			/*for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
					cout << A_graph[i][j] << " ";
				cout << endl;
			}*/
			memset(C_graph, 0, sizeof(C_graph));
		}

		int A=0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				A += A_graph[i][j];
			A_min = min(A_min, A);
			A = 0;
		}

	}

	for (int i = 0; i < n; i++)
	{
		seq[K - m] = spin[i];
		spin.erase(spin.begin() + i);
		search(n - 1, m - 1);
		spin.insert(spin.begin() + i, seq[K - m]);
	}
}

void solve()
{
	search(spin.size(), spin.size());
}

void input()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> graph[i][j];

	for (int i = 0; i < K; i++)
	{
		int y, x, s;
		cin >> y >> x >> s;
		spin.push_back({ y,x,s });
	}
	seq = vector<Spin>(K);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();

	solve();
	cout << A_min;
}
