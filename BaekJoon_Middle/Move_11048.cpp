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
//#include <Windows.h>

using namespace std;
#define FOR(i,m,n) for(int i=(m); i<(n); i++)
#define endl "\n"

int graph[1001][1001];
int cache[1001][1001];
int N, M;
int dy[3] = { 0,1,1 };
int dx[3] = { 1,1,0 };

bool isInside(int ny, int nx)
{
	return ny <= N && nx <= M;
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	FOR(i, 1, N+1)
		FOR(j, 1, M+1)
		cin >> graph[i][j];

	cache[1][1] = graph[1][1];
	memset(cache, -1, sizeof(cache));
}


int solve(int y, int x)
{
	if (y == N && x == M) return graph[N][M];
	if (!isInside(y, x)) return 0;
	if (y <= 0 || x <= 0) return 0;

	int& ret = cache[y][x];
	if (ret != -1)
		return cache[y][x];
	
	return ret = max(solve(y + 1, x), max(solve(y + 1, x + 1), solve(y, x + 1))) + graph[y][x];


}

int main()
{
	input();
	int ans = solve(1, 1);

	/*FOR(i, 1, N+1)
	{
		FOR(j, 1, M+1)
			cout << cache[i][j] << " ";
		cout << endl;
	}*/
	cout << ans;
	return 0;
}