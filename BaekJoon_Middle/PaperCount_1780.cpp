#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <bitset>
#include <cmath>
#include <unordered_map>
using namespace std;

#define FOR(i,n) for(int i=0; i<(n); i++)
#define endl "\n"

int N;
vector<vector<int>> N_vec;
int paper_count[3];

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	N_vec = vector < vector<int>>(N, vector<int>(N, 0));
	FOR(i, N)
	{
		FOR(j, N)
		{
			int a;
			cin >> a;
			N_vec[i][j] = a;
		}
	}
}

void addPaperCount(int value)
{
	//cout << value << " ";
	if (value == -1)
		paper_count[0] ++;
	else if (value == 0)
		paper_count[1] ++;
	else
		paper_count[2] ++;
}

bool isSamePaper(int y, int x, int size)
{
	int std = N_vec[y][x];
	FOR(i, size )
	{
		FOR(j, size )
		{
			//cout << N_vec[y + i][x + j] << " ";
			if (std != N_vec[y + i][x + j])
				return false;
		}
	}
	return true;
}

void divideConquer(int y, int x, int size)
{
	//cout << y << " " << x << endl;

	if (isSamePaper(y, x, size))
	{
		addPaperCount(N_vec[y][x]);
		return;
	}

	if (size == 3)
	{
		FOR(i, 3)
		{
			FOR(j, 3)
			{
				addPaperCount(N_vec[y + i][x + j]);
			}
		}
		return;
	}
	
	FOR(i, 3)
	{
		FOR(j, 3)
		{
			divideConquer(y + (size / 3 * i), x + (size / 3 * j), size / 3);
		}
	}
}

void solve()
{
	bool is_same = isSamePaper(0, 0, N);
	//cout << is_same << endl;
	if (is_same == false)
	{
		divideConquer(0, 0, N_vec.size());
	}
	else
		addPaperCount(N_vec[0][0]);

	FOR(i, 3)
		cout << paper_count[i] << " ";
	cout << endl;
}

int main()
{
	input();
	solve();

	return 0;
}