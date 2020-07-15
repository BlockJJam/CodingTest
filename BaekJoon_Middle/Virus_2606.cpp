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
using namespace std;

#define FOR(i,n) for(int i=0; i<(n); i++)
#define endl "\n"
#define ll unsigned long long
const int MAX = 101;

vector<vector<int>> computerPair;
bool isVirus[101];
int virus_count = 0;
int N, M;

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	computerPair = vector<vector<int>>(N+1);
	
	FOR(i, M)
	{
		int a, b;
		cin >> a >> b;
		computerPair[a].push_back(b);
		computerPair[b].push_back(a);
	}
}

void findVirus(int x)
{
	//cout << "virus" << x << endl;
	if (computerPair[x].size() == 0) return;
	
	FOR(i, computerPair[x].size())
	{
		if (isVirus[computerPair[x][i]] == false)
		{
			isVirus[computerPair[x][i]] = true;
			findVirus(computerPair[x][i]);
		}
	}
}

void solve()
{
	isVirus[1] = true;
	findVirus(1);
	FOR(i, N + 1)
		if (isVirus[i] == true && i != 1)
			virus_count++;

	cout << virus_count << endl;
}

int main()
{
	input();
	solve();

	return 0;
}

