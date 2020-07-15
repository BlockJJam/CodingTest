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
#define endl "\n"
#define ll unsigned long long
int N;
int dp[501][501];
int dm[501][2];

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	FOR(i,1, N+1)
	{
		int a, b;
		cin >> a >> b;
		dm[i][0] = a;
		dm[i][1] = b;
	}
}

void solve()
{
	FOR(d, 1, N)
	{
		FOR(i, 1, N - d + 1)
		{
			int j = i + d;
			int mini = 2147483647;
			FOR(k, i, j)
			{
				int mult_count = dp[i][k] + dp[k + 1][j] + (dm[i][0] * dm[k][1] * dm[j][1]);
				mini = mini > mult_count ? mult_count : mini;
			}
			//cout << "min_multiOperCount : " << i << "," << j << " " << mini << endl;
			dp[i][j] = mini;
		}
	}
	
	cout << dp[1][N] << endl;
}

int main()
{
	input();
	solve();
}