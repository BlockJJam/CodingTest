#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;

#define FOR(i,n) for(int i=0; i<(n); i++)
#define endl "\n"

int N, M, total_count = 0;
int A[51][51];
int B[51][51];

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	FOR(i,N)
	{
		string a;
		cin >> a;
		FOR(j, M)
		{
			A[i][j] = a[j] - '0';
		}
	}

	FOR(i, N)
	{
		string a;
		cin >> a;
		FOR(j, M)
		{
			B[i][j] = a[j] - '0';
		}
	}
	//cout << "input" << endl;
}

bool isInsideMatrix(int ny, int nx)
{
	return ny + 2 < N && nx + 2 < M;
}

void changePoint(int y, int x)
{
	if (!isInsideMatrix(y, x))
	{
		total_count = -1;
		return;
	}
	FOR(i, 3)
		FOR(j, 3)
		if (A[y + i][x + j] == 0)
			A[y + i][x + j] = 1;
		else
			A[y + i][x + j] = 0;

	total_count++;
}

void solve()
{
	FOR(i, N)
		FOR(j, M)
			if (A[i][j] != B[i][j])
			{
				changePoint(i, j);
				if (total_count == -1)
				{
					cout << -1 << endl;
					return;
				}
			}

	cout << total_count<< endl;
}

int main()
{
	input();
	solve();

	return 0;
}