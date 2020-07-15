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
#define MAX_S 1001
int N;
int stones[1001];
int cache[1001];

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	FOR(i, 0, N)
		cin >> stones[i];

	memset(cache, -1, sizeof(cache));
}

int solve(int stone)
{
	if (stone >= N)
		return MAX_S;

	if (stone == N-1)
		return 0;

	int& ret = cache[stone];
	if (ret != -1) return ret;
	ret = 1001;
	FOR(i, 1, stones[stone]+1)
		ret = min(ret, solve(stone + i));

	ret = ret + 1;
	return ret;
}

int main()
{
	input();
	int ans = solve(0);
	
	if (ans >= MAX_S)
		ans = -1;
	cout << ans << endl;

	/*FOR(i, 0, N)
	{
		cout << cache[i] << " ";
	}*/
	return 0;
}