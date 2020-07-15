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
#define INF 987654321

int graph[501];
int preSum[501];
int cache[501][501];

int T, K, ans=0;

void input()
{
	cin >> K;
	FOR(i, 0, K)
	{
		cin >> graph[i];
	}
	preSum[0] = graph[0];
	FOR(i, 1, K+1)
	{
		preSum[i] =preSum[i-1] + graph[i-1];
		//cout << preSum[i] << endl;
	}
}

int mergeFile(int a, int b)
{
	if (a == b)
		return graph[a];

	int& ret = cache[a][b];
	if (ret != -1)
		return ret;

	ret = INF;
	int sum = preSum[b + 1] - preSum[a];
	//cout << preSum[b + 1];
	FOR(i, a, b)
		ret = min(ret, mergeFile(a, i)+ mergeFile(i + 1, b) + sum);

	//cout << a<<" " <<b << " " << sum << " "<< ret << endl;
	return ret;
}

void solve(int k)
{
	int ret = INF;
	
	FOR(i, 0, k - 1)
		ret = min(ret, mergeFile(0, i) + mergeFile(i + 1, k - 1));

	cout << ret << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--)
	{
		input();
		memset(cache, -1, sizeof(cache));
		solve(K);
		
	}
	return 0;
}