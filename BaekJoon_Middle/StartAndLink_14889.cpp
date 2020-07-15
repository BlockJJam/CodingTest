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
vector<int> N_vec, M_vec;
int graph[21][21];
int unselected_point, selected_point, answer = 21 * 21 * 100;

void solve(int n, int m)
{
	if (m == 0)
	{
		int stat_a;
		int stat_b;
		FOR(i, 0, M)
		{
			FOR(j, i + 1, M)
			{
				stat_a = graph[M_vec[i]][M_vec[j]];
				stat_b = graph[M_vec[j]][M_vec[i]];
				selected_point += stat_a + stat_b;

				stat_a = graph[N_vec[i]][N_vec[j]];
				stat_b = graph[N_vec[j]][N_vec[i]];
				unselected_point += stat_a + stat_b;
			}
		}
		
		int diff_point = abs(selected_point - unselected_point);
		//cout << diff_point << endl;

		answer = answer > diff_point ? diff_point : answer;

		selected_point = 0;  unselected_point = 0;
		
		return;
	}

	FOR(i, 0, n)
	{
		M_vec[M - m] = N_vec[i];
		if (M - m > 0 && M_vec[M - m - 1] > M_vec[M - m])
			continue;
		N_vec.erase(N_vec.begin() + i);
		solve(n - 1, m - 1);
		N_vec.insert(N_vec.begin() + i, M_vec[M - m]);
	}
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	M = N / 2;

	FOR(i, 0, N)
		FOR(j, 0, N)
			cin >> graph[i][j];

	N_vec = vector<int>(N, 0);
	FOR(i, 0, N)
		N_vec[i] = i;

	M_vec = vector<int>(M, 0);
}

int main()
{
	input();
	solve(N, M);

	cout << answer;

	return 0;
}
