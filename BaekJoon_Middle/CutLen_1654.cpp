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
#define ll long long

int N, K;
vector<int> lans;
priority_queue <ll> pq;
void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> N;
	int lan;
	FOR(i, 0, K)
	{
		cin >> lan;
		lans.push_back(lan);
	}
}

void solve(ll begin, ll end)
{
	ll N_len = (begin + end) / N;
	int N_cnt = 0;

	FOR(i, 0, K)
		N_cnt += lans[i] / N_len;
	//cout << N_len << " " << N_cnt << endl;
	//cout << begin << " " << end << endl;
	//Sleep(1000);

	ll mid = (begin + end) / 2;

	if (begin >= end)
		return;

	if (N_cnt == N)
	{
		pq.push(N_len);
		solve(mid + 1, end);
	}
	else if (N_cnt < N)
		solve(begin, mid);
	else
	{
		pq.push(N_len);
		solve(mid + 1, end);
	}
}

int main()
{
	input();
	ll totalLanLen = 0;
	FOR(i, 0, K)
	{
		totalLanLen += lans[i];
	}
	solve(0, totalLanLen);

	cout << pq.top() << endl;

	return 0;
}